#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <fftw3.h>

#include "Hilbert.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                                Hilbert                                  //
/////////////////////////////////////////////////////////////////////////////

Hilbert::Hilbert()
{
}

Hilbert::~Hilbert()
{
    if (in != nullptr)
    {
        fftw_destroy_plan(plan_forward);
        fftw_destroy_plan(plan_backward);
        fftw_free(in);
        fftw_free(out);
    }
}

/////////////////////////////////////////////////////////////////////////////
//                         Hilbert Transformation                          //
/////////////////////////////////////////////////////////////////////////////

std::vector<std::vector<double>>& Hilbert::hilbert(const std::vector<double> &src)
{
    if (vvhil.empty() || src.size() != vvhil.front().size())
    {
        vvhil.clear();
        vvhil.resize(2, std::vector<double>(src.size()));

        if (in != nullptr)
        {
            fftw_destroy_plan(plan_forward);
            fftw_destroy_plan(plan_backward);
            fftw_free(in);
            fftw_free(out);

            in = nullptr;
            out = nullptr;
        }
    }

    if (in == nullptr)
    {
        in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * src.size());
        out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * src.size());

        plan_forward = fftw_plan_dft_1d(src.size(), in, out, FFTW_FORWARD, FFTW_ESTIMATE);
        plan_backward = fftw_plan_dft_1d(src.size(), out, in, FFTW_BACKWARD, FFTW_EXHAUSTIVE);
    }

    /// FFT
    for (size_t i = 0; i < src.size(); ++i)
    {
        in[i][0] = src.at(i);
        in[i][1] = 0.;
    }

    fftw_execute(plan_forward);

/*
    /// DEBUG
    for (size_t i = 0; i < src.size(); ++i)
        std::cout << "FFT " << "\t" << out[i][0] << "\t" << out[i][1] << std::endl;
*/

    /// Hilbert
    for (size_t i = 1; i < src.size()/2; ++i)
    {
        out[i][0] *= 2.;
        out[i][1] *= 2.;
    }
    for (size_t i = src.size()/2; i < src.size()-1; ++i)
    {
        out[i][0] = 0.;
        out[i][1] = 0.;
    }

    /// IFFT
    fftw_execute(plan_backward);

    for (size_t i = 0; i < vvhil.front().size(); ++i)
    {
        vvhil.front().at(i) = in[i][0];
        vvhil.back().at(i) = in[i][1];
    }

    normalize(vvhil);

/*
    /// DEBUG
    for (size_t i = 0; i < src.size(); ++i)
        std::cout << "HILBERT " << "\t" << vvhil.front().at(i) << "\t" << vvhil.back().at(i) << std::endl;
*/

    return vvhil;
}

/////////////////////////////////////////////////////////////////////////////
//                           Phase Determination                           //
/////////////////////////////////////////////////////////////////////////////

std::vector<double> &Hilbert::phase()
{
    if (vphase.empty() || vphase.size() != vvhil.front().size())
    {
        vphase.clear();
        vphase.resize(vvhil.front().size());
    }

    for (size_t i = 0; i < vphase.size(); ++i)
    {
        vphase.at(i) = atan2(in[i][1], in[i][0]);
    }

/*
    /// DEBUG
    for (size_t i = 0; i < vphase.size(); ++i)
        std::cout << "PHASE " << vphase.at(i) << std::endl;
*/

    return vphase;
}

std::vector<double>& Hilbert::phase(const std::vector<double> &src)
{
    if (vphase.empty() || vphase.size() != src.size())
    {
        vphase.clear();
        vphase.resize(src.size());
    }

    this->hilbert(src);

    for (size_t i = 0; i < vphase.size(); ++i)
    {
        vphase.at(i) = atan2(in[i][1], in[i][0]);
    }

    return vphase;
}

/////////////////////////////////////////////////////////////////////////////
//                                 Unwrap                                  //
/////////////////////////////////////////////////////////////////////////////

std::vector<double> &Hilbert::unwrap()
{
    if (vwrap.empty() || vwrap.size() != vvhil.front().size())
    {
        vwrap.clear();
        vwrap.resize(vvhil.front().size());
    }

    this->phase();

/*
    double prev = 0.;
    for (size_t i = 0; i < vwrap.size(); ++i)
    {
        vwrap.at(i) = prev + this->angle(vphase.at(i) - prev);
        prev = vphase.at(i);
    }
*/
    double prev = vphase.at(0), val = 0.;
    for (size_t i = 1; i < vwrap.size(); ++i)
    {
        vwrap.at(i) = val = val + this->angle(vphase.at(i) - prev);
        prev = vphase.at(i);
    }

    return vwrap;
}

std::vector<double>& Hilbert::unwrap(const std::vector<double> &src)
{
    if (vwrap.empty() || vwrap.size() != src.size())
    {
        vwrap.clear();
        vwrap.resize(src.size());
    }

    this->hilbert(src);

    this->phase();

    double prev = vphase.at(0), val = 0.;
    for (size_t i = 1; i < vwrap.size(); ++i)
    {
        vwrap.at(i) = val = val + this->angle(vphase.at(i) - prev);
        prev = vphase.at(i);
    }

/*
    /// DEBUG
    for (size_t i = 0; i < vwrap.size(); ++i)
        std::cout << "UNWRAP\t" << vwrap.at(i) << std::endl;
*/

    return vwrap;
}

/////////////////////////////////////////////////////////////////////////////
//                                  Angle                                  //
/////////////////////////////////////////////////////////////////////////////

double Hilbert::angle(double x, double cutoff)
{
    /// equivalent phase variation in [-pi, pi]
    double dps = (x + M_PI) - floor((x + M_PI) / (2*M_PI)) * (2*M_PI) - M_PI;

    /// preserve variation sign for +pi vs. -pi
    if ((dps == -M_PI) && (x > 0.0))
    {
        dps = M_PI;
    }

    /// incremental phase correction
    double dp_corr = dps - x;

    /// Ignore correction when incremental variation is smaller than cutoff
    if (fabs(x) < cutoff)
    {
        dp_corr = 0.0;
    }

    /// Integrate corrections and add to P to produce smoothed phase values
    x += dp_corr;

    if (x < 0.0)
    {
        x = 0.0;
    }

    /// DEBUG
    //std::cout << "ANGLE\t" << x << std::endl;

    return x;

}

} /// SENTENZ
