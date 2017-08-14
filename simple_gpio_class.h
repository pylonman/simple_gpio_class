#pragma once
#include <Arduino.h>
#include <stdint.h>

struct gpio
{
    gpio(uint8_t pin_arg, uint8_t mode) : pin(pin_arg) { pinMode(pin, mode); };
    void write(uint8_t value) const { digitalWrite(pin, value); };
    int read() const { return(digitalRead(pin)); };
    const uint8_t pin;
};
