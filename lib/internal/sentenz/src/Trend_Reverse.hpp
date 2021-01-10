/*
 * Version 1.01
 *
*/

#ifndef TREND_REVERSE_HPP
#define TREND_REVERSE_HPP

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
//
////////////////////////////////////////////////////////////////////////////////

        enum class SOrder : std::int8_t;
 
////////////////////////////////////////////////////////////////////////////////
//                              Trend Reverse                                 //
////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////

	// Variant 2D
	template<typename T>
	auto trend_reverse(const std::vector<std::vector<T>> &src, const size_t &monitor = 2);


	// Variant 1D
	template<typename T>
        SOrder trend_reverse(const std::vector<T> &src, const size_t &monitor = 2);


	// Variant iterator
        SOrder trend_reverse(const auto end, const size_t &monitor = 2);


	// Variant iterator
        SOrder trend(const auto begin, const auto end);

} /// SENTENZ

#include "Trend_Reverse.cpp"

#endif /// TREND_REVERSE_HPP
