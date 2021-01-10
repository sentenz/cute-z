/*
 * Version 1.01
 *
 */

#ifndef HILBERT_HPP
#define HILBERT_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <cstddef>
#include <cstdlib>
#include <cassert>
#include <fftw3.h>

#include "../Stochastic/Stochastic.hpp"

namespace Sentenz
{

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//                          	   HILBERT                                 //
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

    class Hilbert
    {
    public:
        Hilbert();
        ~Hilbert();
        Hilbert(const Hilbert&) = delete;
        const Hilbert& operator=(const Hilbert&) = delete;

        // Function member
        std::vector<std::vector<double>>& hilbert(const std::vector<double> &src);

        std::vector<double>& phase();
        std::vector<double> &phase(const std::vector<double> &src);

        std::vector<double>& unwrap();
        std::vector<double> &unwrap(const std::vector<double> &src);

        double angle(double x, double cutoff = M_PI);

    private:
        // fft members
        fftw_complex *in = nullptr;
        fftw_complex *out = nullptr;
        fftw_plan plan_forward;
        fftw_plan plan_backward;

        // Members
        std::vector<std::vector<double>> vvhil;
        std::vector<double> vwrap;
        std::vector<double> vphase;
    };

} /// SENTENZ

//#include "Hilbert.cpp"

#endif /// HILBERT_HPP
