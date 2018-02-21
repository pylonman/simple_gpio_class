#include "simple_gpio_class.h"

using namespace simple_gpio;

void setup()
{
}

void loop()
{
  Output led{13};
  while(1){
    led.set(HIGH);
    delay(100);
    led.set(LOW);
    delay(100);
  }
}
