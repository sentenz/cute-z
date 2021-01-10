/*
 * Version 1.02
 *
 */

#ifndef STOCHASTIC_HPP
#define STOCHASTIC_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>          /// std::accumulate
#include <complex>
#include <cassert>
#include <iterator>
#include <functional>       /// std::minus, std::find
#include <vector>
#include <memory>           /// std::shared_ptr
#include <typeinfo>

namespace Sentenz
{

#ifndef M_E
#define M_E (2.7182818284590452354)
#endif

#ifndef M_LOG2E
#define M_LOG2E (1.4426950408889634074)
#endif

#ifndef M_LOG10E
#define M_LOG10E (0.43429448190325182765)
#endif

#ifndef M_LN2
#define M_LN2 (0.69314718055994530942)
#endif

#ifndef M_LN10
#define M_LN10 (2.30258509299404568402)
#endif

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#ifndef M_PI_2
#define M_PI_2 (1.57079632679489661923)
#endif

#ifndef M_PI_4
#define M_PI_4 (0.78539816339744830962)
#endif

#ifndef M_1_PI
#define M_1_PI (0.31830988618379067154)
#endif

#ifndef M_2_PI
#define M_2_PI (0.63661977236758134308)
#endif

#ifndef M_2_SQRTPI
#define M_2_SQRTPI (1.12837916709551257390)
#endif

#ifndef M_SQRT2
#define M_SQRT2 (1.41421356237309504880)
#endif

#ifndef M_SQRT1_2
#define M_SQRT1_2 (0.70710678118654752440)
#endif

inline float sDegreesToRadians(float degrees)
{
    return degrees * float(M_PI / 180);
}

inline double sDegreesToRadians(double degrees)
{
    return degrees * double(M_PI / 180);
}

inline float sRadiansToDegrees(float radians)
{
    return radians * float(180 / M_PI);
}

inline double sRadiansToDegrees(double radians)
{
    return radians * double(180 / M_PI);
}


/////////////////////////////////////////////////////////////////////////////
//                               Normalize                                 //
/////////////////////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////////////////////

    inline void normalize(std::vector<double> &src);

    inline void normalize(auto &src);


/////////////////////////////////////////////////////////////////////////////
//                               Mean Value                                //
/////////////////////////////////////////////////////////////////////////////
///
/////////////////////////////////////////////////////////////////////////////

    template<typename T>
    inline auto mu(const T &src);


////////////////////////////////////////////////////////////////////////////////
//                                  Covariance                                //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    auto cov(const T &x, const T &y);


////////////////////////////////////////////////////////////////////////////////
//                                  Variance                                  //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    inline auto var(const T &src);


////////////////////////////////////////////////////////////////////////////////
//                              Standard Deviation                            //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    inline auto std(const T &src);


////////////////////////////////////////////////////////////////////////////////
//                                  Correlation                               //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

    ///
    /// Variant 1D   x|y
    ///
    template<typename T>
    inline auto cor(const std::vector<T> &x, const std::vector<T> &y);


    ///
    /// Variant 2D   X|Y
    ///
    template<typename T>
    auto cor(const std::vector<std::vector<T>> &x, const std::vector<std::vector<T>> &y);


    ///
    /// Variant 2D   X|X
    ///
    template<typename T>
    auto cor(const std::vector<std::vector<T>> &x, const std::string& mode = "");


////////////////////////////////////////////////////////////////////////////////
//                                  Regression                                //
////////////////////////////////////////////////////////////////////////////////
///
///	const int BUF = 1000;
///
///	vector<double> x(BUF), y(BUF), z(BUF);
///
///	for (size_t i = 99; i < y.size()-100; ++i) y.at(i) = 1 + drand();
///
///	iota(x.begin(), x.end(), 0.0);
///
///	z = regres(x, y);
///
///     alternative:
///
///     z = regres(y);
///
////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    auto regres(const T &x, const T &y);

    template<typename T>
    auto regres(const T &y);


////////////////////////////////////////////////////////////////////////////////
//                                  Gradient                                  //
////////////////////////////////////////////////////////////////////////////////
///
/// std::vector<double> r = {1.2, 1.3, 1.1, 1.2, 1.3, 1.4, 1.6};
///
/// std::cout << gradient(r.begin()+4, r.end()) << "\t" << gradient(r) << std::endl;
///
////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    auto gradient(const T &src);

    template<typename T>
    auto gradient(const T begin, const T end);

} /// SENTENZ

#include "Stochastic.cpp"

#endif /// STOCHASTIC_HPP
