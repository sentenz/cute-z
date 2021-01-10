/*
 * Version 1.01
 *
*/

#ifndef BKALMAN_HPP
#define BKALMAN_HPP

#include <Eigen/Dense>

namespace Sentenz
{

typedef const Eigen::Ref<const Eigen::MatrixXd> RefMatrixXd;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                            Kalman-Bucy Filter                              //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///	vector<double> modelX(134,0.0), modelY(134,0.0), modelYm(134,0.0);
///	double Vx = 3.8*.5 , Vy = 3.8*.86, g = 9.80665, t = 0.005;
///
///	for (size_t i = 0; i < modelX.size()-1; i++)
///	{
///		modelX.at(i+1) = modelX.at(i) + Vx*t;
///		modelY.at(i+1) = modelY.at(i) + Vy*t - .5*g*t*t;
///		modelYm.at(i+1) = modelY.at(i) + Vy*t - .5*g*t*t + .05*frand();
///
///		Vy -= g*t;
///	}
///
///	const int n = 4, m = 2, l = 1;
///
///	Matrix<double,n,n> A;			// State transition
///	A << 	1.0, 0.0, t, 0.0,
///             0.0, 1.0, 0.0, t,
///		0.0, 0.0, 1.0, 0.0,
///		0.0, 0.0, 0.0, 1.0;
///	Matrix<double,n,l> X;			// Estimate state
///	X << 	0.0,                                // x
///		0.8,                                // y
///		1.0,                                // Vx
///		1.0;                                // Vy
///	Matrix<double,n,m> B;			// Control
///	B << 	0.0, 0.0,
///		0.0, .5*t*t,                        // 1/2*dt^2
///		0.0, 0.0,
///		0.0, t;                             // dt
///	Matrix<double,m,l> U;			// Control state
///	U << 	0.0,
///		-g;                                 // -g
///	Matrix<double,m,n> H;			// Observation
///	H <<	1.0, 0.0, 0.0, 0.0,
///		0.0, 1.0, 0.0, 0.0;
///	Matrix<double,m,m> R;			// Measurement error
///	R << 	0.01, 0.0,
///		0.0, 0.01;
///	Matrix<double,n,n> P = 1.0 * Eigen::Matrix<double,n,n>::Identity();         // Covariance
///	Matrix<double,n,n> Q = 0.00001 * Eigen::Matrix<double,n,n>::Identity();     // Process error
///
///	Matrix<double,m,l> Z;			// Measurement state
///	MatrixXd Result;
///
///	Kalman Kal( X, P );
///
///	for (size_t i = 1; i < modelY.size(); i++)
///	{
///		Z <<    modelX[i],
///			modelY[i];
///
///		Kal.predict( A, B, U, Q );
///		Result = Kal.correct( Z, H, R );
///		cout << Result << "\t\t" << modelY.at(i) <<  "\t\t" << modelYm.at(i) << "\n\n";
///	}
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///	Zustandsraummodellierung:
///
///	x[k] = A[k] * x[k-1] + B[k] * u[k] + w[k]   // w ~ Q
///	y[k] = C[k] * x[k]   + D[k] * u[k] + v[k]   // v ~ R
///
///	Filter: Correction
///
///	x[k] = A[k] * x[k-1] + B[k] * u[k] + K[k] * (z[k] - H[k] * x[k-1])  // Estimation
///	P[k] = A[k] * P[k-1] * A[k]^T - K[k] * R[k] * K[k]^T + Q[k]         // Covariance: Riccati-Equ.
///	K[k] = P[k] * H[k]^T * R[k]^-1                                      // Kalman Gain
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    class BKalman
    {
    public:
        BKalman() : x(Eigen::MatrixXd::Zero(1, 1)), P(Eigen::MatrixXd::Identity(1, 1)) {}
        BKalman(RefMatrixXd &x_, RefMatrixXd &P_) : x(x_), P(P_) {}
        ~BKalman() = default;
        BKalman(const BKalman&) = delete;
        const BKalman& operator=(const BKalman&) = delete;

        /// updating system status through measurement
        Eigen::MatrixXd correct(RefMatrixXd &A, RefMatrixXd &z, RefMatrixXd &B, RefMatrixXd &u, RefMatrixXd &H, RefMatrixXd &R, RefMatrixXd &Q);

    private:
        Eigen::MatrixXd x;
        Eigen::MatrixXd y;
        Eigen::MatrixXd P;
        Eigen::MatrixXd K;
    };

} /// SENTENZ

#endif /// BKALMAN_HPP
