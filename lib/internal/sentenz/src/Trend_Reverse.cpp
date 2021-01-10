#include <iostream>
#include <exception>
#include <iterator>
#include <cstdint>
#include <algorithm>
#include <typeinfo>

#include "Trend_Reverse.hpp"

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                              Ascending Order                               //
////////////////////////////////////////////////////////////////////////////////

    enum class SOrder : std::int8_t
    {
        Descending = -1, Unsorted, Ascending, Equal
    };
 
////////////////////////////////////////////////////////////////////////////////
//                              Trend Reverse                                 //
////////////////////////////////////////////////////////////////////////////////

    // Variant 2D
    template<typename T>
    auto trend_reverse(const std::vector<std::vector<T>> &src, const size_t &monitor = 2)
    {
        size_t i = 0;

        std::vector<SOrder> orders(src.size());

        for (auto& it : src)
        {
            assert(monitor > 1);

            SOrder currentOrder = SOrder::Equal;

            // Note: an empty range returns true!
            for (auto iter = it.end()-monitor; iter != it.end();)
            {
                auto prev = iter++;

                if (iter != it.end())
                {
                    // Compare neighbors
                    SOrder newOrder = SOrder::Equal;
                    if (*prev < *iter)
                    {
                        newOrder = SOrder::Ascending;
                    }
                    else if (*prev > *iter)
                    {
                        newOrder = SOrder::Descending;
                    }
                    // Any change
                    if (newOrder == SOrder::Equal || currentOrder == newOrder)
                    {
                        ; // No change;
                    }
                    else if (currentOrder == SOrder::Equal)
                    {
                        currentOrder = newOrder; // Order changes
                    }
                    else
                    {
                        currentOrder = SOrder::Unsorted; // must be unsorted
                    }
                }
            }
            orders.at(i++) = currentOrder;
        }

        return orders;
    }


    // Variant 1D
    template<typename T>
    SOrder trend_reverse(const std::vector<T> &src, const size_t &monitor = 2)
    {
        assert(monitor > 1);

        SOrder currentOrder = SOrder::Equal;

        // Note: an empty range returns true!
        for (auto it = src.end()-monitor; it != src.end();)
        {
            auto prev = it++;

            if (it != src.end())
            {
                // Compare neighbors
                SOrder newOrder = SOrder::Equal;
                if (*prev < *it)
                {
                    newOrder = SOrder::Ascending;
                }
                else if (*prev > *it)
                {
                    newOrder = SOrder::Descending;
                }
                // Any change
                if (newOrder == SOrder::Equal || currentOrder == newOrder)
                {
                    ; // No change;
                }
                else if (currentOrder == SOrder::Equal)
                {
                    currentOrder = newOrder; // Order changes
                }
                else
                {
                    currentOrder = SOrder::Unsorted; // must be unsorted
                }
            }
        }

        return currentOrder;
    }


    // Variant iterator
    SOrder trend_reverse(const auto end, const size_t &monitor = 2)
    {
        assert(monitor > 1);

        SOrder currentOrder = SOrder::Equal;

        // Note: an empty range returns true!
        for (auto it = end-monitor; it != end;)
        {
            auto prev = it++;

            if (it != end)
            {
                // Compare neighbors
                SOrder newOrder = SOrder::Equal;
                if (*prev < *it)
                {
                    newOrder = SOrder::Ascending;
                }
                else if (*prev > *it)
                {
                    newOrder = SOrder::Descending;
                }
                // Any change
                if (newOrder == SOrder::Equal || currentOrder == newOrder)
                {
                    ; // No change;
                }
                else if (currentOrder == SOrder::Equal)
                {
                    currentOrder = newOrder; // Order changes
                }
                else
                {
                    currentOrder = SOrder::Unsorted; // must be unsorted
                }
            }
        }

        return currentOrder;
    }

} // namespace Sentenz

