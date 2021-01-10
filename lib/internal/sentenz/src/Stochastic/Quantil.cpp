#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <typeinfo>

#include "Quantil.hpp"

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                                      Median                                //
////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    auto median(const T &src)
    {
        auto tmp = src;

        std::sort(tmp.begin(), tmp.end());

        auto center = (tmp.size()-1)/2;

        if (tmp.size() % 2)
        {
            return tmp.at(center);
        }
        else
        {
            return (tmp.at(center) + tmp.at(center+1))/2.;
        }
    }

////////////////////////////////////////////////////////////////////////////////
//                              Median Filter -DoTo!!!                        //
////////////////////////////////////////////////////////////////////////////////

    template<typename T, typename I>
    auto medianfilt(const T &src, const I &order)
    {
        auto result(src.size()-order+1);
        std::vector<T> values;

        size_t j = 0;

        for (size_t i = 0; i < src.size(); ++i)
        {
            values.push_back(src.at(i));

            if (values.size() == order)
            {
                result.at(j++) = median(values);
                values.erase(values.begin());
            }
        }
        return result;
    }

} /// SENTENZ
