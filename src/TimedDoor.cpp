// Copyright 2021 PollyllyZh
#include<string>
#include <ctime>
#include "TimedDoor.h"


void Timer::sleep(int iTimeout) {
  time_t start = time(nullptr);
  while (time(nullptr) - start < iTimeout) {
    continue;
  }
}

void Timer::tregister(int timeout, TimerClient* client) {
  client = client;
  sleep(timeout);
  client->Timeout();
}

TimedDoor::TimedDoor(int iTimeout_)
    : opened(false),
      adapter(new DoorTimerAdapter(*this)),
      iTimeout(iTimeout_) {}

bool TimedDoor::isDoorOpened() {
    return opened;
}

void TimedDoor::lock() {
    opened = false;
}

void TimedDoor::unlock() {
  opened = true;
  Timer t;
  t.tregister(iTimeout, adapter);
}

void TimedDoor::DoorTimeOut() {
    throw std::string("close the door!");
}

void TimedDoor::throwState() {
  if (opened) {
    throw std::string("the door is opened!");
  } else {
    throw std::string("the door is closed!");
  }
}

DoorTimerAdapter::DoorTimerAdapter(TimedDoor& door_) : door(door_) {}

void DoorTimerAdapter::Timeout() {
    door.DoorTimeOut();
}