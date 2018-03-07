# Simple gpio class for Arduino

Version: 1.1 <br>
Release date: 2018-03-07 <br>

## Summary

A header only C++ wrapper for the Arduino framework that allows you to create and initialize a gpio object with a single line of code.  After initialization the gpio object stores the pin argument so that the user is no longer responsible for keeping track of it.  Like the name suggests it is simple; it only performs digital read and write operations.

## Interface

```
Output(uint8_t pin) : pin_num(pin)
Input(uint8_t pin) : pin_num(pin)
InputPU(uint8_t pin) : pin_num(pin)
```

The Input / Output object is created after passing a pin value to the constructor.  The pin argument is passed and stored within the object on declaration and the Arduino pinMode function is called during construction.

```
uint8_t GPIO::pin() const
```

The pin function returns the value of pin_num.

```
void Output::set(uint8_t value) const
```

The set member function calls the Arduino digitalWrite function.  However, a pin argument is not required as the object already knows what pin it is supposed to use.  Additionally, the assignment operator '=' is overloaded to call the set function.

```
int Input::get() const
```

The get member function calls the Arduino digitalRead function.  Once again, there is no pin argument required.  The  comparison operator '==' is overloaded to compare the result of the get function.
