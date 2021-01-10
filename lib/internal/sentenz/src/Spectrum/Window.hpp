/*
 * Version 1.01
 *
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <iterator>
#include <cstddef>
#include <complex>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <typeinfo>

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                          Window Functions                                  //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///
///	std::vector<double> x(100, 1);
///	std::vector<double> y;
///
///	Window<double> win;
///
///	y = win.blackman(x);
///	// vs
///	win.blackman(x,y);
///
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    template<typename I>
    class Window
    {
    public:
        Window() = default;
        ~Window() = default;
        Window(const Window&) = delete;
        const Window& operator=(const Window&) = delete;

        ///
        /// Hann-Window
        ///
        template<typename T>
        void hann(const T &src, T &dest);

        template<typename T>
        auto& hann(const T& src);

        ///
        /// Hamming-Window
        ///
        template<typename T>
        void hamm(const T &src, T &dest);

        template<typename T>
        auto& hamm(const T &src);

        ///
        /// Blackman-Window
        ///
        template<typename T>
        void blackman(const T &src, T &dest);

        template<typename T>
        auto& blackman(const T &src);

    private:
        std::shared_ptr<std::vector<I>> win;
    };

} /// SENTENZ

#include "Window.cpp"

#endif /// WINDOW_HPP
