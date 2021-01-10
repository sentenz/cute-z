/**
 * @file gpio.h
 * @brief GPIO driver header
 */

#ifndef SENTNEZ_BUS_GPIO_H
#define SENTNEZ_BUS_GPIO_H

#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern  "C" {
#endif // __cplusplus


int gpio_export(const int pin);
int gpio_unexport(const int pin);
int gpio_direction(const int pin, const char *dir);
int gpio_read(const int pin);
int gpio_write(const int pin, const bool level);
int gpio_exist(const int pin);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // SENTNEZ_BUS_GPIO_H
