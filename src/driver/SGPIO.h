#ifndef SSGPIO_H
#define SSGPIO_H

#include <iostream>

enum class IO
{
    Raspi3_IO17 = 17,
    Raspi3_IO18 = 18,
    Raspi3_IO27 = 27,
    Raspi3_IO22 = 22,
    Raspi3_IO23 = 23,
    Raspi3_IO24 = 24,
    Raspi3_IO25 = 25,
    Raspi3_IO05 = 5,
    Raspi3_IO06 = 6,
    Raspi3_IO12 = 12,
    Raspi3_IO13 = 13,
    Raspi3_IO19 = 19,
    Raspi3_IO16 = 16,
    Raspi3_IO26 = 26,
    Raspi3_IO20 = 20,
    Raspi3_IO21 = 21,
    NanoPCT3Plus_IOB26 = 58,
    NanoPCT3Plus_IOC04 = 68,
    NanoPCT3Plus_IOC07 = 71,
    NanoPCT3Plus_IOC08 = 72,
    NanoPCT3Plus_IOC24 = 88,
    NanoPCT3Plus_IOC28 = 92,
};

class SGPIO
{
public:
    SGPIO();
    ~SGPIO();
    const SGPIO& operator=(const SGPIO&) = delete;

    /// Member functions
    int get(const IO pin, const bool enabled = true);
    int set(const IO pin, const bool level = false, const bool enabled = true);
};

#endif /// SSGPIO_H
