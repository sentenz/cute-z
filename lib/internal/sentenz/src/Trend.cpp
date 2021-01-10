#include <iostream>
#include <exception>
#include <iterator>
#include <cstdint>
#include <algorithm>
#include <typeinfo>

#include "Trend.hpp"

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                          Ascending Order                                   //
////////////////////////////////////////////////////////////////////////////////

    enum class Order : std::int8_t
    {
        Descending = -1, Unsorted, Ascending, Equal
    };
 
////////////////////////////////////////////////////////////////////////////////
//                              Trend                                         //
////////////////////////////////////////////////////////////////////////////////

    ///
    /// Variant 2D
    ///

    template<typename T>
    auto trend(const std::vector<std::vector<T>> &src, const size_t &monitor = 1)
    {
        size_t i = 0;

        std::vector<Order> orders(src.size());

        for (auto& it : src)
        {
            assert(monitor > 0);

            Order currentOrder = Order::Equal;

            /// Note: an empty range returns true!
            for (auto iter = it.begin(); iter != it.begin() + monitor;)
            {
                auto prev = iter++;

                if (iter != it.begin() + monitor)
                {
                    /// Compare neighbors
                    Order newOrder = Order::Equal;

                    if (*prev > *iter)
                    {
                        newOrder = Order::Ascending;
                    }
                    else if (*prev < *iter)
                    {
                        newOrder = Order::Descending;
                    }
                    /// Any change
                    if (newOrder == Order::Equal || currentOrder == newOrder)
                    {
                        ; /// No change;
                    }
                    else if (currentOrder == Order::Equal)
                    {
                        currentOrder = newOrder; /// Order changes
                    }
                    else
                    {
                        currentOrder = Order::Unsorted; /// must be unsorted
                    }
                }
            }
            orders.at(i++) = currentOrder;
        }

        return orders;
    }


    ///
    /// Variant 1D
    ///

    template<typename T>
    Order trend(const std::vector<T> &src, const size_t &monitor = 1)
    {
        assert(monitor > 0);

        Order currentOrder = Order::Equal;

        /// Note: an empty range returns true!
        for (auto it = src.begin(); it != src.begin() + monitor;)
        {
            auto prev = it++;

            if (it != src.begin() + monitor)
            {
                /// Compare neighbors
                Order newOrder = Order::Equal;

                if (*prev > *it)
                {
                    newOrder = Order::Ascending;
                }
                else if (*prev < *it)
                {
                    newOrder = Order::Descending;
                }
                /// Any change
                if (newOrder == Order::Equal || currentOrder == newOrder)
                {
                    ; /// No change;
                }
                else if (currentOrder == Order::Equal)
                {
                    currentOrder = newOrder; /// Order changes
                }
                else
                {
                    currentOrder = Order::Unsorted; /// must be unsorted
                }
            }
        }

        return currentOrder;
    }


        ///
        /// Variant iterator
        ///

	Order trend(const auto end, const size_t &monitor = 2)
	{
		assert(monitor > 1);

		Order currentOrder = Order::Equal;

                /// Note: an empty range returns true!
		for (auto it = end-monitor; it != end;)
		{
			auto prev = it++;

			if (it != end)
			{
                                /// Compare neighbors
				Order newOrder = Order::Equal;
				if (*prev < *it)
				{
					newOrder = Order::Ascending;
				}
				else if (*prev > *it)
				{
					newOrder = Order::Descending;
				}
                                /// Any change
				if (newOrder == Order::Equal || currentOrder == newOrder)
				{
                                        ; /// No change;
				}
				else if (currentOrder == Order::Equal)
				{
                                        currentOrder = newOrder; /// Order changes
				}
				else
				{
                                        currentOrder = Order::Unsorted; /// must be unsorted
				}
			}
		}

		return currentOrder;
	}


        ///
        /// Variant iterator
        ///

	Order trend(const auto begin, const auto end)
	{
		Order currentOrder = Order::Equal;

                /// Note: an empty range returns true!
		for (auto it = begin; it != end;)
		{
			auto prev = it++;

			if (it != end)
			{
                                /// Compare neighbors
				Order newOrder = Order::Equal;
				if (*prev < *it)
				{
					newOrder = Order::Ascending;
				}
				else if (*prev > *it)
				{
					newOrder = Order::Descending;
				}
                                /// Any change
				if (newOrder == Order::Equal || currentOrder == newOrder)
				{
                                        ; /// No change;
				}
				else if (currentOrder == Order::Equal)
				{
                                        currentOrder = newOrder; /// Order changes
				}
				else
				{
                                        currentOrder = Order::Unsorted; /// must be unsorted
				}
			}
		}

		return currentOrder;
	}

} /// SENTENZ
