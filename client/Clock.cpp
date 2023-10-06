/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Clock
*/

#include <iostream>

#include "Clock.hpp"

Clock::Clock(int fps) {
  auto lastUpdate = Clock::getNowMilliseconds();
  _lastUpdate = lastUpdate;
  _actualUpdate = lastUpdate;
  _fps = fps;
}

Clock::~Clock() {}

bool Clock::checkFrame() {
  auto actualTime = Clock::getNowMilliseconds();
  int64_t timePerFrame = 1000 / _fps;
  if (actualTime - _actualUpdate > timePerFrame) {
    _lastUpdate = _actualUpdate;
    _actualUpdate = actualTime;
    return true;
  }
  return false;
}

float Clock::getDeltaTimeSeconds() const {
  float time = _actualUpdate - _lastUpdate;
  float result = time / 1000;
  return result;
}

int64_t Clock::getDeltaTimeMilliseconds() const {
  return _actualUpdate - _lastUpdate;
}