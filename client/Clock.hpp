/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_
#include <chrono>

class Clock {
public:
  Clock(int fps);
  ~Clock();

  bool checkFrame();
  float getDeltaTimeSeconds() const;
  int64_t getDeltaTimeMilliseconds() const;

  static int64_t getNowMilliseconds() {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
  }

private:
  int _fps;
  int64_t _lastUpdate;
  int64_t _actualUpdate;
};

#endif /* !CLOCK_HPP_ */
