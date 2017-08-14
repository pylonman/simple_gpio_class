# Simple gpio class for Arduino

Version: 1.0 <br>
Release date: 2017-07-19 <br>

## Summary

C++ library for the Arduino IDE that allows you to create and initialize a gpio object with a single line of code.  After initialization the gpio object stores the pin argument so that the caller is no longer responsible for keeping track of it.  Like the name suggests it is simple; only performs digital read and write operations.

## Interface

```
gpio(uint8_t pin_arg, uint8_t mode) : pin(pin_arg)
```

The gpio object is created after passing a pin and mode value to the constructor.  The pin argument is stored within the object and the Arduino pinMode function is called which completes initialization of both the object and gpio pin.

```
const uint8_t pin;
```

The gpio pin variable is initialized upon object creation.

```
void write(uint8_t value) const
```

The write member function calls the Arduino digitalWrite function.  However, a pin argument is not required as the object already knows what pin it is supposed to use

```
int read() const
```

The read member function calls the Arduino digitalRead function.  Once again, there is no pin argument required.
