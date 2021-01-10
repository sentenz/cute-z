#include "HKalman.hpp"


namespace Sentenz
{

    void HKalman::predict(RefMatrixXd &A, RefMatrixXd &B, RefMatrixXd &u, RefMatrixXd &Q)
    {
        x = A * x + B * u;

        P = A * P + P * A.transpose() + Q;
    }

    Eigen::MatrixXd HKalman::correct(RefMatrixXd &z, RefMatrixXd &H, RefMatrixXd &R)
    {
        S = H * P * H.transpose() + R;

        K = P * H.transpose() * S.inverse();

        P = P - K * H * P;

        x = x + K * (z - H * x);

        return H * x;
    }

} /// SENTENZ
