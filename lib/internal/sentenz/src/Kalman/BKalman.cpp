#include "BKalman.hpp"


namespace Sentenz
{

    Eigen::MatrixXd BKalman::correct(RefMatrixXd &A, RefMatrixXd &B, RefMatrixXd &u, RefMatrixXd &Q, RefMatrixXd &z, RefMatrixXd &H, RefMatrixXd &R)
    {
        K = P * H.transpose() * R.inverse();

        P = A * P + P * A.transpose() - K * R * K.transpose() + Q;

        x = A * x + B * u + K * (z - H * x);

        return H * x;
    }

} /// SENTENZ
