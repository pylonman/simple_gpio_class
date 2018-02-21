#include "simple_gpio_class.h"

using namespace simple_gpio;

void setup()
{
}

void loop()
{
  Output led{13};
  while(1){
    led = HIGH;
    delay(100);
    led = LOW;
    delay(100);
  }
}
