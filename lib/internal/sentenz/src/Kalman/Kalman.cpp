#include "Kalman.hpp"


namespace Sentenz
{

    void Kalman::predict(RefMatrixXd &A, RefMatrixXd &B, RefMatrixXd &u, RefMatrixXd &Q)
    {
        x = A * x + B * u;

        P = A * P * A.transpose() + Q;
    }

    Eigen::MatrixXd Kalman::correct(RefMatrixXd &z, RefMatrixXd &H, RefMatrixXd &R)
    {
        S = H * P * H.transpose() + R;

        K = P * H.transpose() * S.inverse();

        P = P - K * H * P;

        x = x + K * (z - H * x);

        return H * x;
    }

} /// SENTENZ
