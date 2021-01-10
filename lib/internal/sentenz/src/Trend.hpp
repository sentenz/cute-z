/*
 * Version 1.01
 *
*/

#ifndef TREND_HPP
#define TREND_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <cstdint>
#include <algorithm>
#include <typeinfo>

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                              Ascending Order                               //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

	enum class Order : std::int8_t; 
 
////////////////////////////////////////////////////////////////////////////////
//                                  Trend                                     //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

        ///
        /// Variant 2D
        ///
	template<typename T>
	auto trend(const std::vector<std::vector<T>> &src, const size_t &monitor = 2);

        ///
        /// Variant 1D
        ///
	template<typename T>
	Order trend(const std::vector<T> &src, const size_t &monitor = 2);

        ///
        /// Variant iterator
        ///
	Order trend(const auto end, const size_t &monitor = 2);

        ///
        /// Variant iterator
        ///
	Order trend(const auto begin, const auto end);

} /// SENTENZ

#include "Trend.cpp"

#endif /// TREND_HPP
