// Copyright 2021 GHA Test Team
#include "TimedDoor.h"
#include <iostream>

int main() {
  TimedDoor tDoor(6);
  tDoor.lock();
  tDoor.unlock();

  return 0;
}
