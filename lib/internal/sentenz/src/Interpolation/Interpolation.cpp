#include "Interpolation.hpp"

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
    //                              Lineare Spline                                //
    ////////////////////////////////////////////////////////////////////////////////

    template<typename I>
    template<typename T>
    auto& Interpolation<I>::linear(const T &x, const T &y)
    {
        if (s.size() != x.back()-x.front()+1)
        {
            s.resize(x.back()-x.front()+1);
        }

        size_t k = 0;

        for (size_t i = 0; i < x.size()-1; ++i)
        {
            for (size_t j = x.at(i); j < x.at(i+1); ++j)
            {
                s.at(k++) = y.at(i) + ((y.at(i+1)-y.at(i)) * (j-x.at(i))) / (x.at(i+1)-x.at(i));
            }
        }
        s.at(k) = y.back();

        return s;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //                              Cubic Spline                                  //
    ////////////////////////////////////////////////////////////////////////////////

    template<typename I>
    template<typename T>
    auto& Interpolation<I>::cubic(const T &x, const T &y)
    {
        T h(x.size()-1);
        for (size_t i = 0; i < x.size()-1; ++i)
        {
            h.at(i) = x.at(i+1)-x.at(i);
        }

        T g(x.size()-1, 0.);
        for (size_t i = 1; i < x.size()-1; ++i)
        {
            g.at(i) = 3.*((y.at(i+1)-y.at(i))/h.at(i) - (y.at(i)-y.at(i-1))/h.at(i-1));
        }

        T l(x.size(), 1.);
        T m(x.size(), 0.);
        T z(x.size(), 0.);
        for (size_t i = 1; i < x.size()-1; ++i)
        {
            l.at(i) = 2.*(x.at(i+1)-x.at(i-1)) - h.at(i-1)*m.at(i-1);
            m.at(i) = h.at(i) / l.at(i);
            z.at(i) = (g.at(i)-h.at(i-1)*z.at(i-1)) / l.at(i);
        }

        T a = y;
        T b(x.size()-1);
        T c(x.size(), 0.);
        T d(x.size()-1);
        for (int j = x.size()-2; j >= 0; --j)
        {
            c.at(j) = z.at(j) - m.at(j)*c.at(j+1);
            b.at(j) = (a.at(j+1)-a.at(j))/h.at(j) - h.at(j)*(c.at(j+1)+2.*c.at(j))/3.;
            d.at(j) = (c.at(j+1)-c.at(j))/3./h.at(j);
        }

        if (s.size() != x.back()-x.front()+1)
        {
            s.resize(x.back()-x.front()+1);
        }

        size_t k = 0;
        for (size_t i = 0; i < x.size()-1; ++i)
        {
            for (size_t j = x.at(i); j < x.at(i+1); ++j)
            {
                s.at(k++) = a.at(i) + b.at(i)*(j-x.at(i)) + c.at(i)*pow(j-x.at(i),2) + d.at(i)*pow(j-x.at(i),3);
            }
        }
        s.at(k) = y.back();

        return s;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                          Spectral Interpolation                         //
    /////////////////////////////////////////////////////////////////////////////

    template<typename I>
    template<typename T>
    I Interpolation<I>::spectral(const T &x)
    {
        try
        {
            /// Find Peak
            auto magnitud = std::max_element(x.begin(), x.end());
            int peak = std::distance(x.begin(), magnitud);

            double min = x.at(peak-1);
            double plus = x.at(peak+1);

            return static_cast<I>(peak) + .5*(log(min) - log(plus)) / (log(min) + log(plus) - 2.*log(*magnitud));
        }
        catch(...)
        {
            return 0;
        }
    }

} /// SENTENZ
