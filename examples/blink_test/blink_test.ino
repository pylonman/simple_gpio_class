#include "simple_gpio_class.h"

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  gpio led{13, OUTPUT};
  while(1){
    led.write(HIGH);
    delay(100);
    led.write(LOW);
    delay(100);
  }
}
