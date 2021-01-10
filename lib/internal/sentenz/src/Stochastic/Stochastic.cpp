#include "Stochastic.hpp"

#include <iostream>
#include <exception>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>		/// std::accumulate
#include <complex>
#include <cassert>
#include <iterator>
#include <functional>           /// std::minus, std::find
#include <vector>
#include <memory>		/// std::shared_ptr
#include <typeinfo>
#include <float.h>


namespace Sentenz
{

    /////////////////////////////////////////////////////////////////////////////
    //                                Normalize                                //
    /////////////////////////////////////////////////////////////////////////////

    inline void normalize(std::vector<double> &src)
    {
        double value = *std::max_element(src.begin(), src.end());

        for (auto& it : src)
        {
            it /= value;
        }

        return;
    }

    inline void normalize(auto &src)
    {
        double value = *std::max_element(src.front().begin(), src.front().end());

        for (auto& it : src)
        {
            for (auto& iter : it)
            {
                iter /= value;
            }
        }

        return;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                               Mean Value                                //
    /////////////////////////////////////////////////////////////////////////////

    template<typename T>
    inline auto mu(const T &src)
    {
        return std::accumulate(std::begin(src), std::end(src), 0.) / src.size();
    }

    /////////////////////////////////////////////////////////////////////////////
    //                               Covariance                                //
    /////////////////////////////////////////////////////////////////////////////

    template<typename T>
    auto cov(const T &x, const T &y)
    {
        /// Mean Value
        auto mu_x = mu(x);
        auto mu_y = mu(y);

        auto result(0.);

        for (size_t i = 0; i < x.size(); ++i)
        {
            result += (x.at(i) - mu_x)*(y.at(i) - mu_y);
        }

        if (!result)
        {
            result = FLT_MIN;
        }

        return result / (x.size()-1);
    }

    /////////////////////////////////////////////////////////////////////////////
    //                                Variance                                 //
    /////////////////////////////////////////////////////////////////////////////

    template<typename T>
    inline auto var(const T &src)
    {
        return cov(src, src);
    }

    /////////////////////////////////////////////////////////////////////////////
    //                           Standard Deviation                            //
    /////////////////////////////////////////////////////////////////////////////

    template<typename T>
    inline auto std(const T &src)
    {
        return sqrt(var(src));
    }

    /////////////////////////////////////////////////////////////////////////////
    //                               Correlation                               //
    /////////////////////////////////////////////////////////////////////////////

    ///
    /// Variant 1D   x|y
    ///
    template<typename T>
    inline auto cor(const std::vector<T> &x, const std::vector<T> &y)
    {
        return cov(x, y) / (std(x) * std(y));
    }

    ///
    /// Variant 2D   X|Y
    ///
    template<typename T>
    auto cor(const std::vector<std::vector<T>> &x, const std::vector<std::vector<T>> &y)
    {
        std::vector<std::vector<T>> result(x.size(), std::vector<T>(y.size()));

        for (size_t i = 0; i < x.size(); ++i)
        {
            for (size_t j = 0; j < y.size(); ++j)
            {
                result.at(i).at(j) = cov(x.at(i), y.at(j)) / (std(x.at(i)) * std(y.at(j)));
            }
        }

        return result;
    }

    ///
    /// Variant 2D   X|X
    ///
    template<typename T>
    auto cor(const std::vector<std::vector<T>> &x, const std::string &mode)
    {
        std::vector<std::vector<T>> result(x.size(), std::vector<T>(x.size()));

        for (size_t i = 0; i < x.size(); ++i)
        {
            for (size_t j = 0; j < x.size(); ++j)
            {
                if (mode == "")
                {
                    result.at(i).at(j) = cov(x.at(i), x.at(j)) / (std(x.at(i)) * std(x.at(j)));
                }
                else if (mode == "abs")
                {
                    result.at(i).at(j) = fabs(cov(x.at(i), x.at(j)) / (std(x.at(i))*std(x.at(j))));
                }
            }
        }

        return result;
    }

    /////////////////////////////////////////////////////////////////////////////
    //                               Regression                                //
    /////////////////////////////////////////////////////////////////////////////

    template<typename T>
    auto regres(const T &y)
    {
        T x(y.size());
        iota(x.begin(), x.end(), .0);

        return regres(x, y);
    }

    template<typename T>
    auto regres(const T &x, const T &y)
    {
        try
        {
            if (x.size() != y.size())
            {
                throw std::runtime_error("The size of vectors isn't equidistant!\n");
            }

            auto a = cov(x, y) / var(x);
            auto b = mu(y) - a * mu(x);

            T result(x.size());

            for (size_t i = 0; i < x.size(); ++i)
            {
                result.at(i) = a * x.at(i) + b;
            }

            return result;
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
            return static_cast<T>(-1);
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
            return static_cast<T>(-1);
        }
    }

    /////////////////////////////////////////////////////////////////////////////
    //                               Gradient                                  //
    /////////////////////////////////////////////////////////////////////////////

    template<typename T>
    auto gradient(const T &src)
    {
        auto r = regres(src);
        auto m = (r.back() - r.front()) / r.size();

        return atan(m);
    }

    template<typename T>
    auto gradient(const T begin, const T end)
    {
        std::vector<double> src;
        for (auto it = begin; it != end; ++it)
        {
            src.push_back(*it);
        }

        return gradient(src);
    }

} /// SENTENZ
