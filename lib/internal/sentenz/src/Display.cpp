#include <iostream>
#include <exception>
#include <cstring>
#include <vector>
#include <iterator>

#include "Display.hpp"

namespace Sentenz
{
	
////////////////////////////////////////////////////////////////////////////////
//                              Display                                       //
////////////////////////////////////////////////////////////////////////////////

    ///
    /// Variant 3D Vector
    ///

    template<typename T>
    void display(const std::vector<std::vector<std::vector<T>>> &data)
    {
        try
        {
            if (data.empty())
            {
                throw std::runtime_error("Display(): File is empty!");
            }

            std::cout << std::endl;

            for (auto& it : data)
            {
                for (auto& iter : it)
                {
                    for (auto& iterat : iter)
                    {
                        std::cout << iterat << "\t";
                    }
                }

                std::cout << std::endl;
            }
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }


    ///
    /// Variant 2D Vector
    ///

    template<typename T>
    void display(const std::vector<std::vector<T>> &data)
    {
        try
        {
            if (data.empty())
            {
                throw std::runtime_error("Display(): File is empty!");
            }

            std::cout << std::endl;

            for (auto& it : data)
            {
                for (auto& iter : it)
                {
                    std::cout << iter << "\t";
                }

                std::cout << std::endl;
            }
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }


    ///
    /// Variant 1D Vector
    ///

    template<typename T>
    void display(const std::vector<T> &data)
    {
        try
        {
            if (data.empty())
            {
                throw std::runtime_error("Display(): File is empty!");
            }

            std::cout << std::endl;

            for (auto& it : data)
            {
                std::cout << it << "\t";
            }

            std::cout << std::endl;
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }
	
} /// SENTENZ
