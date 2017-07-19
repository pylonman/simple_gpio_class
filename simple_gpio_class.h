#pragma once
#include <Arduino.h>
#include <stdint.h>

class gpio
{
public:
    gpio(uint8_t pin_arg, uint8_t mode) : pin(pin_arg) { pinMode(pin, mode); };
public:
    void write(uint8_t value) const { digitalWrite(pin, value); };
    uint8_t read() const { return(digitalRead(pin)); };
    const uint8_t pin;
};