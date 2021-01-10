/*
 * Version 1.01
 *
 */

#ifndef FOURIER_HPP
#define FOURIER_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <cstddef>
#include <cstdlib>
#include <cassert>
#include <fftw3.h>

#include "Window.hpp"
#include "../Interpolation/Interpolation.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//                          	   FOURIER                                 //
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
///
///
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

    class Fourier : private Window<double>, Interpolation<double>
    {
    public:
        Fourier();
        ~Fourier();
        Fourier(const Fourier&) = delete;
        const Fourier& operator=(const Fourier&) = delete;

        // Function member
        std::vector<std::vector<double>>& fft(const std::vector<double> &src, const char *win = "");

        std::vector<double> &ifft();
        std::vector<double> &ifft(const std::vector<double> &src, const char *win = "");
        std::vector<double> &ifft(const std::vector<std::vector<double>> &src);

        std::vector<double> &psd();
        std::vector<double> &psd(const std::vector<double> &src, const char *win = "");

	double frequency();
        double frequency(const std::vector<double> &src, const char *win = "");

        std::vector<double> &phase();
        std::vector<double> &phase(const std::vector<double> &src, const char *win = "");

        double phaseShift(const std::vector<double> &src0, const std::vector<double> &src1, const auto &win = "");

    private:
	// fft members
	fftw_complex *in = nullptr;
	fftw_complex *out = nullptr;
	fftw_plan plan_forward;
	fftw_plan plan_backward;

        // Members
        double phase_shift = 0.0;

        std::vector<std::vector<double>> vvfft;
        std::vector<double> vifft;
        std::vector<double> vwin;
        std::vector<double> vpsd;
        std::vector<double> vphase;
    };

} /// SENTENZ

//#include "Fourier.cpp"

#endif /// FOURIER_HPP
