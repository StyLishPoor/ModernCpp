#include <iostream>
#include "car.h"

int main()
{
  CCar c;
  c.supply(10);
  c.move();
  c.move();
  c.supply(5);
  return 0;
}
