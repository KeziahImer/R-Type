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

private:
  int _fps;
  std::chrono::duration<long long, std::ratio<1, 10000000>> _lastUpdate;
  std::chrono::duration<long long, std::ratio<1, 10000000>> _actualUpdate;
};

#endif /* !CLOCK_HPP_ */
