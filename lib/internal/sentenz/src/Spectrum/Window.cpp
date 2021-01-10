#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <cstddef>
#include <complex>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <typeinfo>

#include "Window.hpp"

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                                  Hann                                      //
////////////////////////////////////////////////////////////////////////////////

    template<typename I>
    template<typename T>
    void Window<I>::hann(const T &src, T &dest)
    {
        if (src.size() != dest.size())
        {
            dest.resize(src.size());
        }

        for (size_t i = 1; i < src.size()-1; ++i)
        {
            dest.at(i) = src.at(i)*.5*(1.-cos(2.*M_PI*i/src.size()));
        }
    }


    template<typename I>
    template<typename T>
    auto& Window<I>::hann(const T &src)
    {
        if (!win)
        {
            win = std::make_shared<T>(src.size());
        }
        else if (win->size() != src.size())
        {
            win.reset(new T(src.size()));
        }

        for (size_t i = 1; i < src.size()-1; ++i)
        {
            win->at(i) = src.at(i)*.5*(1.-cos(2.*M_PI*i/src.size()));
        }

        return *win;
    }

////////////////////////////////////////////////////////////////////////////////
//                                  Hamming                                   //
////////////////////////////////////////////////////////////////////////////////

    template<typename I>
    template<typename T>
    void Window<I>::hamm(const T &src, T &dest)
    {
        if (src.size() != dest.size())
        {
            dest.resize(src.size());
        }

        for (size_t i = 1; i < src.size()-1; ++i)
        {
            dest.at(i) = src.at(i)*(.54-.46*cos(2.*M_PI*i/src.size()));
        }
    }


    template<typename I>
    template<typename T>
    auto& Window<I>::hamm(const T &src)
    {
        if (!win)
        {
            win = std::make_shared<T>(src.size());
        }
        else if (win->size() != src.size())
        {
            win.reset(new T(src.size()));
        }

        for (size_t i = 1; i < src.size()-1; ++i)
        {
            win->at(i) = src.at(i)*(.54-.46*cos(2.*M_PI*i/src.size()));
        }

        return *win;
    }

////////////////////////////////////////////////////////////////////////////////
//                                  Blackman                                  //
////////////////////////////////////////////////////////////////////////////////

    template<typename I>
    template<typename T>
    void Window<I>::blackman(const T &src, T &dest)
    {
        if (src.size() != dest.size())
        {
            dest.resize(src.size());
        }

        for (size_t i = 1; i < src.size()-1; ++i)
        {
            dest.at(i) = src.at(i)*(.42-.5*cos(2.*M_PI*i/src.size())+.08*cos(4.*M_PI*i/src.size()));
        }
    }


    template<typename I>
    template<typename T>
    auto& Window<I>::blackman(const T &src)
    {
        if (!win)
        {
            win = std::make_shared<T>(src.size());
        }
        else if (win->size() != src.size())
        {
            win.reset(new T(src.size()));
        }

        for (size_t i = 1; i < src.size()-1; ++i)
        {
            win->at(i) = src.at(i)*(.42-.5*cos(2.*M_PI*i/src.size())+.08*cos(4.*M_PI*i/src.size()));
        }

        return *win;
    }

} /// SENTENZ
