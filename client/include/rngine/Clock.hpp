/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Clock
*/

#ifndef _RNGINE_CLOCK_HPP_
#define _RNGINE_CLOCK_HPP_
#include <chrono>

class Clock {
public:
  Clock(int fps) {
    auto lastUpdate = Clock::getNowMilliseconds();
    _lastUpdate = lastUpdate;
    _actualUpdate = lastUpdate;
    _fps = fps;
  }

  bool checkFrame() {
    auto actualTime = Clock::getNowMilliseconds();
    int64_t timePerFrame = 1000 / _fps;
    if (actualTime - _actualUpdate > timePerFrame) {
      _lastUpdate = _actualUpdate;
      _actualUpdate = actualTime;
      return true;
    }
    return false;
  }

  float getDeltaTimeSeconds() const {
    float time = _actualUpdate - _lastUpdate;
    float result = time / 1000;
    return result;
  }

  int64_t getDeltaTimeMilliseconds() const {
    return _actualUpdate - _lastUpdate;
  }

  static int64_t getNowMilliseconds() {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
  }

private:
  int _fps;
  int64_t _lastUpdate;
  int64_t _actualUpdate;
};

#endif
