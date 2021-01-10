#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <fftw3.h>

#include "../Stochastic.hpp"
#include "Fourier.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
//                                Fourier                                  //
/////////////////////////////////////////////////////////////////////////////

Fourier::Fourier()
{

}

Fourier::~Fourier()
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
//                         Fourier Transformation                          //
/////////////////////////////////////////////////////////////////////////////

std::vector<std::vector<double>>& Fourier::fft(const std::vector<double> &src, const char *win)
{
    if (vvfft.empty() || src.size() != vvfft.front().size())
    {
        vwin.clear();
        vvfft.clear();

        vwin.resize(src.size());
        vvfft.resize(2, std::vector<double>(src.size()));

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
    }

    /// Window Functions
    if (strcmp(win, "") == 0)
    {
        vwin = std::move(src);
    }
    else if (strcmp(win, "blackman") == 0)
    {
        vwin  = this->blackman(src);
    }
    else if (strcmp(win, "hann") == 0)
    {
        vwin  = this->hann(src);
    }
    else if (strcmp(win, "hamm") == 0)
    {
        vwin  = this->hamm(src);
    }

#ifdef S_DEBUG
    for (size_t i = 0; i < src.size(); ++i)
        std::cout << "Source " << "\t" << src.at(i) << "\t" << vwin.at(i) << std::endl;
#endif

    for (size_t i = 0; i < src.size(); ++i)
    {
        in[i][0] = vwin.at(i);
        in[i][1] = 0.;
    }

    plan_forward = fftw_plan_dft_1d(src.size(), in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan_forward);


#ifdef S_DEBUG
    for (size_t i = 0; i < src.size(); ++i)
        std::cout << "FFT " << "\t" << out[i][0] << "\t" << out[i][1] << std::endl;
#endif

    for (size_t i = 0; i < src.size(); ++i)
    {
        vvfft.front().at(i) = out[i][0];
        vvfft.back().at(i) = out[i][1];
    }

    return vvfft;
}

/////////////////////////////////////////////////////////////////////////////
//                      Inverse Fourier Transformation                     //
/////////////////////////////////////////////////////////////////////////////

std::vector<double>& Fourier::ifft()
{
    if (vifft.empty() || vifft.size() != vvfft.front().size())
    {
        vifft.clear();
        vifft.resize(vvfft.front().size());
    }

    plan_backward = fftw_plan_dft_1d(vifft.size(), out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan_backward);

    for (size_t i = 0; i < vifft.size(); ++i)
    {
        vifft.at(i) = in[i][0];
    }

    normalize(vifft);

    return vifft;
}

std::vector<double>& Fourier::ifft(const std::vector<double> &src, const char *win)
{
    if (vifft.empty() || vifft.size() != src.size())
    {
        vifft.clear();
        vifft.resize(src.size());
    }

    this->fft(src, win);

    plan_backward = fftw_plan_dft_1d(vifft.size(), out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan_backward);

    for (size_t i = 0; i < vifft.size(); ++i)
    {
        vifft.at(i) = in[i][0];
    }

    normalize(vifft);

    return vifft;
}

std::vector<double>& Fourier::ifft(const std::vector<std::vector<double>> &src)
{
    if (vifft.empty() || vifft.size() != src.front().size())
    {
        vifft.clear();
        vifft.resize(src.front().size());
    }

    for (size_t i = 0; i < vifft.size(); ++i)
    {
        out[i][0] = src.front().at(i);
        out[i][1] = src.back().at(i);
    }

    plan_backward = fftw_plan_dft_1d(vifft.size(), out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan_backward);

    for (size_t i = 0; i < vifft.size(); ++i)
    {
        vifft.at(i) = in[i][0];
    }

    normalize(vifft);

    return vifft;
}

/////////////////////////////////////////////////////////////////////////////
//                         Power Spectral Density                          //
/////////////////////////////////////////////////////////////////////////////

std::vector<double>& Fourier::psd()
{
    if (vpsd.empty() || vpsd.size() != vvfft.front().size()/2)
    {
        vpsd.clear();
        vpsd.resize(vvfft.front().size()/2);
    }

    for (size_t i = 0; i < vpsd.size(); ++i)
    {
        vpsd.at(i) = fabs(pow(out[i][0], 2)) + fabs(pow(out[i][1], 2));
    }

    return vpsd;
}

std::vector<double>& Fourier::psd(const std::vector<double> &src, const char *win)
{
    if (vpsd.empty() || vpsd.size() != src.size()/2)
    {
        vpsd.clear();
        vpsd.resize(src.size()/2);
    }

    this->fft(src, win);

    for (size_t i = 0; i < vpsd.size(); ++i)
    {
        vpsd.at(i) = fabs(pow(out[i][0], 2)) + fabs(pow(out[i][1], 2));
    }

#ifdef S_DEBUG
    for (size_t i = 0; i < vpsd.size(); ++i)
        std::cout << "PSD " << "\t" << vpsd.at(i) << std::endl;
#endif

    return vpsd;
}

/////////////////////////////////////////////////////////////////////////////
//                                Frequency                                //
/////////////////////////////////////////////////////////////////////////////

double Fourier::frequency()
{
    this->psd();

    /// Spectral Interpolation
    return this->spectral(vpsd);
}

double Fourier::frequency(const std::vector<double> &src, const char *win)
{
    this->psd(src, win);

    /// Spectral Interpolation
    return this->spectral(vpsd);
}

/////////////////////////////////////////////////////////////////////////////
//                           Phase Determination                           //
/////////////////////////////////////////////////////////////////////////////

std::vector<double>& Fourier::phase()
{
    if (vphase.empty() || vphase.size() != vvfft.front().size())
    {
        vphase.clear();
        vphase.resize(vvfft.front().size());
    }

    for (size_t i = 0; i < vphase.size(); ++i)
    {
        vphase.at(i) = atan2(out[i][1], out[i][0]);
    }

    return vphase;
}

std::vector<double>& Fourier::phase(const std::vector<double> &src, const char *win)
{
    if (vphase.empty() || vphase.size() != src.size())
    {
        vphase.clear();
        vphase.resize(src.size());
    }

    this->fft(src, win);

    for (size_t i = 0; i < vphase.size(); ++i)
    {
        vphase.at(i) = atan2(out[i][1], out[i][0]);
    }

    return vphase;
}

/////////////////////////////////////////////////////////////////////////////
//                       Phase Shift Determination                         //
/////////////////////////////////////////////////////////////////////////////

double Fourier::phaseShift(const std::vector<double> &src0, const std::vector<double> &src1, const auto &win)
{
    
    double phase0 = this->phase(src0, &win);
    double phase1 = this->phase(src1, &win);

    std::cout << phase0 << std::endl;
    std::cout << phase1 << std::endl;

    phase_shift = phase1 - phase0;

    if (phase_shift < 0)
    {
        phase_shift += sRadiansToDegrees(M_2_PI);
    }
    else if (phase_shift > sRadiansToDegrees(M_2_PI))
    {
        phase_shift -= sRadiansToDegrees(M_2_PI);
    }
    
    return phase_shift;
}

} /// SENTENZ
