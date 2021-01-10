#include "SEngine.h"
#include "../build/SGlobal.h"
#include "../driver/SGPIO.h"

#include <vector>
#include <QApplication>
#include <QDebug>


SEngine::SEngine(const BUS &bus) : busMode(bus)
{
    switch (busMode)
    {
        case BUS::Wire1:
        {
            #ifdef S_UNUSED
            this->ssr = new UniSSR("29-0000001863fe", "output");
            this->ssr->setPath(QString(::GlobalBus1Wire).toStdString());
            #endif
        }
            break;

        case BUS::I2C:
        {
        }
            break;

        case BUS::GPIO:
        {
            this->gpio = new SGPIO;
        }
            break;

        default:
            break;
    }
}

SEngine::~SEngine()
{
    if (this->gpio != nullptr)
    {
        delete this->gpio;
        this->gpio = nullptr;
    }
    #ifdef S_UNUSED
    if (this->ssr != nullptr)
    {
        delete this->ssr;
        this->ssr = nullptr;
    }
    #endif
}

void SEngine::forward(Engine type)
{
    this->active = true;

    switch (this->busMode)
    {
    case BUS::Wire1:
    {
        #ifdef S_UNUSED
        std::vector<SSR> relays;

        switch (type)
        {
            case Engine::EMotor:
            {
                relays = {SSR::R1, SSR::R2, SSR::R3};
            }
                break;
            case Engine::Cylinder:
            {
                relays = {SSR::R5, SSR::R7};
            }
                break;
            default:
                break;
        }

        this->ssr->latch(relays);
        #endif
    }
        break;

    case BUS::I2C:
    {
    }
        break;

    case BUS::GPIO:
    {
        switch (type)
        {
            case Engine::EMotor:
            {
            this->gpio->set(IO::Raspi3_IO26, true);
            }
                break;
            default:
                break;
        }
    }
        break;

    default:
        break;
    }
}

void SEngine::backward(Engine type)
{
    this->active = true;

    switch (this->busMode)
    {
    case BUS::Wire1:
    {
        #ifdef S_UNUSED
        std::vector<SSR> relays;

        switch (type)
        {
            case Engine::EMotor:
            {
                relays = {SSR::R1, SSR::R2, SSR::R4};
            }
                break;
            case Engine::Cylinder:
            {
                relays = {SSR::R6, SSR::R8};
            }
                break;
            default:
                break;
        }

        this->ssr->latch(relays);
        #endif
    }
        break;

    case BUS::I2C:
    {
    }
        break;

    case BUS::GPIO:
    {
        switch (type)
        {
            case Engine::EMotor:
            {
                this->gpio->set(IO::Raspi3_IO19, true);
            }
                break;
            default:
                break;
        }
    }
        break;

    default:
        break;
    }
}

void SEngine::neutral(Engine type)
{
    this->active = false;

    switch (this->busMode)
    {
    case BUS::Wire1:
    {
        #ifdef S_UNUSED
        std::vector<SSR> relays;

        switch (type)
        {
            case Engine::EMotor:
            {
                relays = {SSR::R1, SSR::R2, SSR::R3, SSR::R4};
            }
                break;
            case Engine::Cylinder:
            {
                relays = {SSR::R5, SSR::R6, SSR::R7, SSR::R8};
            }
                break;
            default:
                break;
        }

        this->ssr->unlatch(relays);
        #endif
    }
        break;

    case BUS::I2C:
    {
    }
        break;

    case BUS::GPIO:
    {
        switch (type)
        {
            case Engine::EMotor:
            {
                this->gpio->set(IO::Raspi3_IO19, false, false);
                this->gpio->set(IO::Raspi3_IO26, false, false);
            }
                break;
            default:
                break;
        }
    }
        break;

    default:
        break;
    }
}

bool SEngine::isActive() const
{
    return this->active;
}
