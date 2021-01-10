/*
 * Version 1.01
 *
*/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <exception>
#include <cstring>
#include <vector>
#include <iterator>

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                                  Display                                   //
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////

    ///
    /// Variant 3D Vector
    ///
    template<typename T>
    void display(const std::vector<std::vector<std::vector<T>>> &data);
	
    ///
    /// Variant 2D Vector
    ///
    template<typename T>
    void display(const std::vector<std::vector<T>> &data);
	
    ///
    /// Variant 1D Vector
    ///
    template<typename T>
    void display(const std::vector<T> &data);

} /// SENTENZ

#include "Display.cpp"

#endif /// DISPLAY_HPP
