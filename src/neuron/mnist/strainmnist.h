#ifndef STRAINMNIST_H
#define STRAINMNIST_H

#include <iostream>

#include "tiny_dnn/tiny_dnn.h"

namespace neuron_mnist
{
    static void construct_net(tiny_dnn::network<tiny_dnn::sequential> &nn, tiny_dnn::core::backend_t backend_type);

    static void train_lenet(const std::string &data_dir_path, double learning_rate, const int n_train_epochs, const int n_minibatch, tiny_dnn::core::backend_t backend_type);

    static tiny_dnn::core::backend_t parse_backend_name(const std::string &name);

    int train(std::string data_path = "", double learning_rate = 1, int epochs = 30, int minibatch_size = 16, tiny_dnn::core::backend_t backend_type = tiny_dnn::core::default_engine());
}
#endif /// STRAINMNIST_H
