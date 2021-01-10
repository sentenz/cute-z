/*
 * Version 1.01
 *
*/

#ifndef NEURON_HPP
#define NEURON_HPP

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

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                      Artificial Neuronal Network                           //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///	vector<double> u(5,0);
///	u.insert(u.end(),20,1);
///	u.insert(u.end(),20,0);
///
///	vector<double> y(u.size(),0);
///	for (size_t i = 1; i < u.size(); i++)
///		y.at(i) = .2*u.at(i) + .8*y.at(i-1);
///
///	vector<double> ones(u.size(),1);
///
///	vector<vector<double>> trainingsLayer  {u, y, ones};
///
///	Eigen::MatrixXd U(3, u.size());
///	for (size_t i = 0; i < trainingsLayer.size(); i++)
///	{
///		U.row(i) = VectorXd::Map(&trainingsLayer[i][0], trainingsLayer.at(i).size());
///	}
///
///
///	Neuron Network(3,1);
///	Network.train(U, U.row(1));
///
///
///	vector<double> soll(5,0);
///	soll.insert(soll.end(),15,.5);
///	soll.insert(soll.end(),10,0);
///	soll.insert(soll.end(),10,-1);
///	soll.insert(soll.end(),10,.5);
///	soll.insert(soll.end(),5,1);
///
///	vector<double> ysoll(soll.size(),0);
///	for (size_t i = 1; i < soll.size(); i++)
///		ysoll.at(i) = .2*soll.at(i) + .8*ysoll.at(i-1);
///
///	ones.resize(soll.size(),1);
///
///	vector<vector<double>> Layer {soll, ysoll, ones};
///
///	U.setZero();
///	U.resize(3,soll.size());
///	for (size_t i = 0; i < Layer.size(); i++)
///	{
///		U.row(i) = VectorXd::Map(&Layer[i][0], Layer.at(i).size());
///	}
///
///	Eigen::MatrixXd Y;
///	Y = Network.validat(U);
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

	class Neuron
	{
	public:
                Neuron(auto _s = 1, auto _o = 1, const auto& _net = "sigmiod") : s(_s), o(_o), net(_net) {}
		~Neuron() = default;
		Neuron(const Neuron&) = delete;
		const Neuron& operator=(const Neuron&) = delete;

                /// Network Training
		void train(Eigen::MatrixXd U, Eigen::MatrixXd m, const auto error);
                /// Validation of the model
		Eigen::MatrixXd validat(Eigen::Ref<Eigen::MatrixXd> U); // Eigen::MatrixXd m

	private:
                /// Activationsfunction
		Eigen::MatrixXd threshold(Eigen::MatrixXd X);

		int s, o;
		const std::string net;
		Eigen::MatrixXd W_I;
		Eigen::MatrixXd W_O;
		Eigen::MatrixXd B_O;
		Eigen::MatrixXd V;
		Eigen::MatrixXd y;
	};

} /// SENTENZ

#include "Neuron.cpp"

#endif /// NEURON_HPP
