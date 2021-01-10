/*
 * Version 1.01
 *
*/

#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <complex>
#include <cassert>
#include <iterator>
#include <vector>
#include <memory>
#include <typeinfo>


namespace Sentenz
{

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    //                                Interpolation                               //
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    ///
    ///	vector<double> x {1,7,12,15,19};
    ///	vector<double> y {8,10,7,8,7};
    ///
    ///	vector<double> rl, rc;
    ///
    ///	Interpolation<double> spline;
    ///
    ///	rl = spline.linear(x,y);
    ///	rc = spline.cubic(x,y);
    ///
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////

    template<typename I>
    class Interpolation
    {
    public:
        Interpolation() = default;
        ~Interpolation() = default;
        const Interpolation& operator=(const Interpolation&) = delete;

        /// Linear Spline
        template<typename T>
        auto& linear(const T &x, const T &y);

        /// Cubic Spline
        template<typename T>
        auto& cubic(const T &x, const T &y);

        /// Spectral Interpolation
        template<typename T>
        I spectral(const T &x);


    private:
        std::vector<I> s;
    };

} /// SENTENZ

#include "Interpolation.cpp"

#endif /// INTERPOLATION_HPP
