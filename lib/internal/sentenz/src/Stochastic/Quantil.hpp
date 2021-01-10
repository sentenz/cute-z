/*
 * Version 1.01
 *
*/

#ifndef QUANTIL_HPP
#define QUANTIL_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <typeinfo>

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                                      Median                                //
////////////////////////////////////////////////////////////////////////////////
///
///	std::vector<double> x {1.2, 1.3, 3.3, 7.5, 2.1};
///
///	std::cout << median(x) << std::endl;	// 2.1
///
////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	auto median(const T &src);

////////////////////////////////////////////////////////////////////////////////
//                              Median Filter -DoTo!!!                        //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

	template<typename T, typename I>
	auto medianfilt(const T &src, const I &order);

} /// SENTENZ

#include "Quantil.cpp"

#endif /// QUANTIL_HPP
