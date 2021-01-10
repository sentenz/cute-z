#include "strainmnist.h"

namespace neuron_mnist
{
    static void construct_net(tiny_dnn::network<tiny_dnn::sequential> &nn,
                              tiny_dnn::core::backend_t backend_type) {
        // connection table [Y.Lecun, 1998 Table.1]
    #define O true
    #define X false
        // clang-format off
        static const bool tbl[] = {
            O, X, X, X, O, O, O, X, X, O, O, O, O, X, O, O,
            O, O, X, X, X, O, O, O, X, X, O, O, O, O, X, O,
            O, O, O, X, X, X, O, O, O, X, X, O, X, O, O, O,
            X, O, O, O, X, X, O, O, O, O, X, X, O, X, O, O,
            X, X, O, O, O, X, X, O, O, O, O, X, O, O, X, O,
            X, X, X, O, O, O, X, X, O, O, O, O, X, O, O, O
        };
        // clang-format on
    #undef O
    #undef X

        // construct nets
        //
        // C : convolution
        // S : sub-sampling
        // F : fully connected
        // clang-format off
        using fc = tiny_dnn::layers::fc;
        using conv = tiny_dnn::layers::conv;
        using batch_norm = tiny_dnn::batch_normalization_layer;
        using l2_norm = tiny_dnn::l2_normalization_layer;
        using max_pool = tiny_dnn::layers::max_pool;
        using relu = tiny_dnn::activation::relu;
        using dropout = tiny_dnn::dropout_layer;
        using softmax = tiny_dnn::activation::softmax;

        using tiny_dnn::core::connection_table;
        using padding = tiny_dnn::padding;

        nn << conv(32, 32, 5, 1, 8,   // C1, in:32x32x1, 5x5conv, out:28x28x6
                   padding::valid, true, 1, 1, 1, 1, backend_type)
//           << l2_norm(28*28, 8)
           << relu()
           << max_pool(28, 28, 8, 2)   // S2, in:28x28x6, 2x2pooling, out:14x14x6
           << relu()
           << conv(14, 14, 3, 8, 16,   // C3, in:14x14x6, 5x5conv, 16fmaps out:10x10x16
                   connection_table(tbl, 8, 16),
                   padding::valid, true, 1, 1, 1, 1, backend_type)
//           << l2_norm(12*12, 16)
           << relu()
           << max_pool(12, 12, 16, 2)  // S4,  in:10x10x16, 2x2pooling, out:5x5x16
           << relu()
           << conv(6, 6, 3, 16, 32,   // C5, in:5x5x16, 5x5conv, out:4x4x32
                   padding::valid, true, 1, 1, 1, 1, backend_type)
           << relu()
           << fc(512, 100, true, backend_type)  // F6, 120-in, 10-out
           << relu()
           << fc(100, 10, true, backend_type)  // F6, 120-in, 10-out
           << softmax();
    }

    static void train_lenet(const std::string &data_dir_path,
                            double learning_rate,
                            const int n_train_epochs,
                            const int n_minibatch,
                            tiny_dnn::core::backend_t backend_type)
    {
        // specify loss-function and learning strategy
        tiny_dnn::network<tiny_dnn::sequential> nn;
        tiny_dnn::adagrad optimizer;

        construct_net(nn, backend_type);

        std::cout << "load models..." << std::endl;

        // load MNIST dataset
        std::vector<tiny_dnn::label_t> train_labels, test_labels;
        std::vector<tiny_dnn::vec_t> train_images, test_images;

        tiny_dnn::parse_mnist_labels(data_dir_path + "/train-labels-idx1-ubyte",
                                     &train_labels);
        tiny_dnn::parse_mnist_images(data_dir_path + "/train-images-idx3-ubyte",
                                     &train_images, -1.0, 1.0, 2, 2);
        tiny_dnn::parse_mnist_labels(data_dir_path + "/t10k-labels-idx1-ubyte",
                                     &test_labels);
        tiny_dnn::parse_mnist_images(data_dir_path + "/t10k-images-idx3-ubyte",
                                     &test_images, -1.0, 1.0, 2, 2);

        std::cout << "start training" << std::endl;

        tiny_dnn::progress_display disp(train_images.size());
        tiny_dnn::timer t;

        optimizer.alpha *= std::min(tiny_dnn::float_t(4),
                                    static_cast<tiny_dnn::float_t>(sqrt(n_minibatch) * learning_rate));

        int epoch = 1;
        // create callback
        auto on_enumerate_epoch = [&]() {
            std::cout << "Epoch " << epoch << "/" << n_train_epochs << " finished. "
                      << t.elapsed() << "s elapsed." << std::endl;
            ++epoch;
            tiny_dnn::result res = nn.test(test_images, test_labels);
            std::cout << res.num_success << "/" << res.num_total << std::endl;

            disp.restart(train_images.size());
            t.restart();
        };

        auto on_enumerate_minibatch = [&]() { disp += n_minibatch; };

        // training
        nn.train<tiny_dnn::mse>(optimizer,
                                train_images,
                                train_labels,
                                n_minibatch,
                                n_train_epochs,
                                on_enumerate_minibatch,
                                on_enumerate_epoch);

        std::cout << "end training." << std::endl;

        // test and show results
        nn.test(test_images, test_labels).print_detail(std::cout);
        // save network model & trained weights
        nn.save("LeNet-model");
    }

    static tiny_dnn::core::backend_t parse_backend_name(const std::string &name)
    {
        const std::array<const std::string, 5> names = {{
                                                            "internal", "nnpack", "libdnn", "avx", "opencl",
                                                        }};
        for (size_t i = 0; i < names.size(); ++i)
        {
            if (name.compare(names[i]) == 0)
            {
                return static_cast<tiny_dnn::core::backend_t>(i);
            }
        }

        return tiny_dnn::core::default_engine();
    }

    int train(std::string data_path,
              double learning_rate,
              int epochs,
              int minibatch_size,
              tiny_dnn::core::backend_t backend_type)
    {
        if (data_path == "") {
            std::cout << "Data path not specified." << std::endl;
            return -1;
        }
        if (learning_rate <= 0) {
            std::cout
                    << "Invalid learning rate. The learning rate must be greater than 0." << std::endl;
            return -1;
        }
        if (epochs <= 0) {
            std::cout << "Invalid number of epochs. The number of epochs must be greater than 0." << std::endl;
            return -1;
        }
        if (minibatch_size <= 0 || minibatch_size > 60000) {
            std::cout << "Invalid minibatch size. The minibatch size must be greater than 0 and less than dataset size (60000)." << std::endl;
            return -1;
        }
        std::cout << "Running with the following parameters:" << std::endl
                  << "Data path: " << data_path << std::endl
                  << "Learning rate: " << learning_rate << std::endl
                  << "Minibatch size: " << minibatch_size << std::endl
                  << "Number of epochs: " << epochs << std::endl
                  << "Backend type: " << backend_type << std::endl
                  << std::endl;
        try {
            train_lenet(data_path, learning_rate, epochs, minibatch_size, backend_type);
        } catch (tiny_dnn::nn_error &err) {
            std::cout << "Exception: " << err.what() << std::endl;
        }

        return 0;
    }
}
