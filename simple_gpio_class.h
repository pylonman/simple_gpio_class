#pragma once
#include <Arduino.h>
#include <stdint.h>

namespace simple_gpio
{
	class gpio
	{
	protected:
		gpio(const uint8_t pin): pin_num(pin) {};
		const uint8_t pin_num;
	public:
		uint8_t pin() const { return pin_num; };
	};

	class Output : public gpio
	{
	public:
		Output(uint8_t pin): gpio(pin) { pinMode(pin_num, OUTPUT); };
		void set(uint8_t value) const { digitalWrite(pin_num, value); };
		void operator =(uint8_t value) { set(value); };
		~Output() { pinMode(pin_num, INPUT); };
	};

	class Input : public gpio
	{
	public:
		Input(uint8_t pin): gpio(pin) { pinMode(pin_num, INPUT); };
		int get() const { return digitalRead(pin_num); };
		bool operator ==(int state) { return digitalRead(pin_num) == state ? true : false; };
		operator bool() { return digitalRead(pin_num); };
	};
	
	class InputPU : public gpio
	{
	public:
		InputPU(uint8_t pin): gpio(pin) { pinMode(pin_num, INPUT_PULLUP); };
		int get() const { return digitalRead(pin_num); };
		bool operator ==(int state) { return digitalRead(pin_num) == state ? true : false; };
		operator bool() { return digitalRead(pin_num); };
	};

	namespace active_high
	{
		constexpr uint8_t high = HIGH;
		constexpr uint8_t low = LOW;
	}

	namespace active_low
	{
		constexpr uint8_t high = LOW;
		constexpr uint8_t low = HIGH;
	}
}
