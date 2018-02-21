#pragma once
#include <Arduino.h>
#include <stdint.h>

namespace simple_gpio
{
    class gpio
    {
    protected:
        gpio(const uint8_t pin_a): pin_num(pin_a) {};
        const uint8_t pin_num;
    public:
        uint8_t pin() const { return pin_num; };
    };

    class Output : public gpio
    {
    public:
        Output(const uint8_t pin): gpio(pin) { pinMode(pin_num, OUTPUT); };
        void set(const uint8_t value) const { digitalWrite(pin_num, value); };
        void operator =(const uint8_t value) { set(value); };
        ~Output() { pinMode(pin_num, INPUT); };
    };

    class Input : public gpio
    {
    public:
        Input(const uint8_t pin): gpio(pin) { pinMode(pin_num, INPUT); };
        Input(const uint8_t pin, const uint8_t mode): gpio(pin) { pinMode(pin_num, INPUT_PULLUP); };
        int get() const { return digitalRead(pin_num); };
        bool operator ==(const int state) { return digitalRead(pin_num) == state ? true : false; };
        operator bool() { return digitalRead(pin_num); };
    };

    namespace active_high
    {
        const uint8_t high = HIGH;
        const uint8_t low = LOW;
    }

    namespace active_low
    {
        const uint8_t high = LOW;
        const uint8_t low = HIGH;
    }
}
