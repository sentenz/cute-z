#include "SGPIO.h"

#include <Bus>

SGPIO::SGPIO()
{
}

SGPIO::~SGPIO()
{
}

///
/// @brief Read input.
///
/// @return 0 if successful read operation. -1 otherwise.
///
int SGPIO::get(const IO pin, const bool enabled)
{
    int res = 0;

    if (!gpio_exist((int)pin))
    {
        /// Export
        res = gpio_export((int)pin);
    }

    res = gpio_direction((int)pin, "in");
    res = gpio_read((int)pin);

    if (gpio_exist((int)pin))
    {
        /// Unexport
        if (!enabled)
        {
            res = gpio_unexport((int)pin);
        }
    }

    return res;
}

///
/// @brief Write output.
///
/// @return 0 if successful read operation. -1 otherwise.
///
int SGPIO::set(const IO pin, const bool level, const bool enabled)
{
    int res = 0;

    if (!gpio_exist((int)pin))
    {
        /// Export
        res = gpio_export((int)pin);
    }

    res = gpio_direction((int)pin, "out");
    res = gpio_write((int)pin, level);

    if (gpio_exist((int)pin))
    {
        /// Unexport
        if (!enabled)
        {
            res = gpio_unexport((int)pin);
        }
    }

    return res;
}
