// Copyright 2021 PollyllyZh
#include "TimedDoor.h"
#include <iostream>
#include <ctime>

int main() {
  TimedDoor tDoor(5);
  tDoor.lock();
  tDoor.unlock();

  return 0;
}
