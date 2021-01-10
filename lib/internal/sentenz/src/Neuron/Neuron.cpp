#include "Neuron.hpp"

#include <iostream>
#include <exception>
#include <cmath>
#include <iterator>

#include <Eigen/Dense>
#include <unsupported/Eigen/MatrixFunctions>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                          Activationsfunction                            //
/////////////////////////////////////////////////////////////////////////////

    Eigen::MatrixXd Neuron::threshold(Eigen::MatrixXd X)
    {
        if (net == "sigmiod")
        {
            X = -2*X.array();
            X = 1+X.array().exp();

            return 2/X.array()-1;
        }
        else if (net == "gauss")
        {
            X = -.5*X.array()*X.array();

            return X.array().exp();
        }
        else if (net == "signum")
        {
            for (auto i = 0; i < X.rows(); ++i)
            {
                for (auto j = 0; j < X.cols(); ++j)
                {
                    if (X(i,j) > 0)
                    {
                        X(i,j) = 1;
                    }
                    else if (X(i,j) == 0)
                    {
                        X(i,j) = 0;
                    }
                    else if (X(i,j) < 0)
                    {
                        X(i,j) = -1;
                    }
                }
            }

            return X;
        }
        else
        {
            throw std::runtime_error("Unknown Activationsfunction in Neuron::threshold()\n");
        }
    }

/////////////////////////////////////////////////////////////////////////////
//                            Network Training                             //
/////////////////////////////////////////////////////////////////////////////

	void Neuron::train(Eigen::MatrixXd U, Eigen::MatrixXd m, const auto error = 1.e-4)
	{
		auto N = U.cols();
		auto r = U.rows();
		auto n = (r+1)*s+1;
		auto mu = .01;

		W_I = Eigen::MatrixXd::Random(s,r);
		W_O = Eigen::MatrixXd::Random(o,s);
		B_O = Eigen::MatrixXd::Random(o,1);

		Eigen::MatrixXd W_I_new;
		Eigen::MatrixXd W_O_new;
		Eigen::MatrixXd B_O_new;
		Eigen::MatrixXd Delta_W;
		Eigen::MatrixXd Delta_W_I = 0.*W_I;
		Eigen::MatrixXd Delta_W_O = 0.*W_O;
		Eigen::MatrixXd Delta_B_O = 0.*B_O;

		Eigen::MatrixXd R;
		Eigen::MatrixXd E, E_old;
		Eigen::MatrixXd S;
		Eigen::MatrixXd I = Eigen::MatrixXd::Identity(n,n);
		Eigen::MatrixXd J = Eigen::MatrixXd::Zero(N,n);

                ///
                /// Activationsfunction
                ///
		V = this->threshold(W_I * U);

		if (B_O.size() == 1)
		{
			y = W_O * V;
			y = y.array() + B_O(0);
		}
		else
		{
			y = W_O * V + B_O;
		}

		E = .5*(m-y) * (m.transpose()-y.transpose());
		E_old = E;
		R = m-y;

                ///
                /// Training
                ///
		while (E(0) > error && mu < 1.e10)
		{
			J.col(n-1) = Eigen::VectorXd::LinSpaced(N,-1,-1);

			for (auto i = 0; i < s; ++i)
			{
				for (auto k = 0; k < N; ++k)
				{
					J(k,n-s+i-1) = -V(i,k);
				}
			}

			auto index = 0;

			for (auto j = 0; j < r; ++j)
			{
				for (auto i = 0; i < s; ++i)
				{
					for (auto k = 0; k < N; ++k)
					{
						J(k,index) = -W_O(i) * (1-V(i,k)*V(i,k)) * U(j,k);
					}

					index++;
				}
			}

			S = J.transpose() * J + mu * I;
			Delta_W = (-1)*(S.inverse() * J.transpose() * R.transpose());

			index = 0;

		    for (auto j = 0; j < r; ++j)
		    {
				for (auto i = 0; i < s; ++i)
				{
					Delta_W_I(i,j) = Delta_W(index++);
				}
			}

			for (auto i = 0; i < s; ++i)
			{
				Delta_W_O(i) = Delta_W(index++);
			}

			Delta_B_O(0) = Delta_W(index++);

			W_O_new = W_O + Delta_W_O;
			B_O_new = B_O + Delta_B_O;
			W_I_new = W_I + Delta_W_I;

                        ///
                        /// Activationsfunction
                        ///
			V = this->threshold(W_I_new * U);

			if (B_O_new.size() == 1)
			{
				y = W_O_new * V;
				y = y.array() + B_O_new(0);
			}
			else
			{
				y = W_O_new * V + B_O_new;
			}

			E = .5*(m-y) * (m.transpose()-y.transpose());
			R = m-y;

			if (E(0) < E_old(0))
			{
				mu = .5*mu;
				W_O = W_O_new;
				B_O = B_O_new;
				W_I = W_I_new;
				E_old = E;
			}
			else
			{
				mu = 2.*mu;
			}
		}

		V.setZero();
		y.setZero();
	}

/////////////////////////////////////////////////////////////////////////////
//                            Network Validation                           //
/////////////////////////////////////////////////////////////////////////////

	Eigen::MatrixXd Neuron::validat(Eigen::Ref<Eigen::MatrixXd> U) //, Eigen::MatrixXd m
	{
		V.resize(s, U.cols());
		y.resize(1, U.cols());

                ///
                /// Activationsfunction
                ///

		V = this->threshold(W_I * U);

		if (B_O.size() == 1)
		{
			y = W_O * V;

			return y.array() + B_O(0);
		}
		else
		{
			return W_O * V + B_O;
		}
	}

} /// SENTENZ
