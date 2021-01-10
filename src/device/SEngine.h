#ifndef SENGINE_H
#define SENGINE_H

class SGPIO;

enum class BUS
{
    Wire1 = 0,
    I2C = 1,
    GPIO = 2
};

enum class Engine
{
    EMotor = 0,
    Cylinder = 1
};


class SEngine
{
public:
    explicit SEngine(const BUS &bus);
    ~SEngine();

    void forward(Engine type);
    void backward(Engine type);
    void neutral(Engine type);

    bool isActive() const;

private:

    bool active = false;
    BUS busMode;

    SGPIO *gpio = nullptr;
};

#endif /// SENGINE_H
