#include "gpio.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

///
/// @brief export using sysfs interface.
///
/// @return 0 if successful.
///
int gpio_export(const int pin)
{
    int m_buffersize = 100;
    char buffer[m_buffersize];/// Output buffer
    ssize_t bytes;                  /// Bytes written
    int fd;                         /// Filedescriptor
    int res;                        /// Result

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0)
    {
        printf("Failed to open export for writing!\n");
        return -1;
    }

    bytes = snprintf(buffer, m_buffersize, "%d", pin);
    res = write(fd, buffer, bytes);
    if (res < 0)
    {
        printf("Failed to write pin for export!\n");
    }

    close(fd);

    return res;
}

///
/// @brief unexport using sysfs interface.
///
/// @return 0 if successful.
///
int gpio_unexport(const int pin)
{
    int m_buffersize = 100;
    char buffer[m_buffersize];/// Output buffer
    ssize_t bytes;                  /// Bytes written
    int fd;                         /// Filedescriptor
    int res;                        /// Result

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd < 0)
    {
        printf("Failed to open unexport for writing!\n");
        return -1;
    }

    bytes = snprintf(buffer, m_buffersize, "%d", pin);
    res = write(fd, buffer, bytes);
    if (res < 0)
    {
        printf("Failed to write pin for unexport!\n");
    }

    close(fd);

    return res;
}

///
/// @brief direction using sysfs interface.
///
/// @return 0 if successful.
///
int gpio_direction(const int pin, const char *dir)
{
    int m_buffersize = 100;
    char path[m_buffersize];    /// Output buffer
    int fd;                         /// Filedescriptor
    int res;                        /// Result

    snprintf(path, m_buffersize, "/sys/class/gpio/gpio%d/direction", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0)
    {
        printf("Failed to open gpio direction for writing!\n");
        return -1;
    }

    res = write(fd, dir, sizeof dir);
    if (res < 0)
    {
        printf("Failed to set direction!\n");
    }

    close(fd);

    return res;
}

///
/// @brief read using sysfs interface.
///
/// @return 0 if successful.
///
int gpio_read(const int pin)
{
    int m_buffersize = 100;
    char path[m_buffersize];
    char value[3] = {0};
    int fd;

    snprintf(path, m_buffersize, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("Failed to open gpio value for reading!\n");
        return -1;
    }

    if (read(fd, value, 3) < 0)
    {
        printf("Failed to read value!\n");
    }

    close(fd);

    return atoi(value);
}

///
/// @brief write using sysfs interface.
///
/// @return 0 if successful.
///
int gpio_write(const int pin, const bool level)
{
    int m_buffersize = 100;
    char path[m_buffersize];
    int fd;
    int res;

    snprintf(path, m_buffersize, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_WRONLY);
    if (fd < 0)
    {
        printf("Failed to open gpio value for writing!\n");
        return -1;
    }

    if (level)
    {
        res = write(fd, "1", 1);
    }
    else if (!level)
    {
        res = write(fd, "0", 1);
    }

    if (res < 0)
    {
        printf("Failed to write value!\n");
    }

    close(fd);

    return res;
}

///
/// @brief status using sysfs interface.
///
/// @return 0 if successful.
///
int gpio_exist(const int pin)
{
    int m_buffersize = 100;
    char path[m_buffersize];
    struct stat buffer;

    snprintf(path, m_buffersize, "/sys/class/gpio/gpio%d", pin);

    return (stat(path, &buffer) == 0);
}
