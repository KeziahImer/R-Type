/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Clock
*/

#include <iostream>

#include "Clock.hpp"

Clock::Clock(int fps)
{
    auto lastUpdate = std::chrono::system_clock::now().time_since_epoch();
    _lastUpdate = lastUpdate;
    _actualUpdate = lastUpdate;
    _fps = fps;
}

Clock::~Clock()
{
}

bool Clock::checkFrame()
{
    auto actualTime = std::chrono::system_clock::now().time_since_epoch();
    int64_t timePerFrame = 1000 / _fps;
    if (std::chrono::duration_cast<std::chrono::milliseconds>(actualTime - _actualUpdate).count() > timePerFrame)
    {
        _lastUpdate = _actualUpdate;
        _actualUpdate = actualTime;
        return true;
    }
    return false;
}

float Clock::getDeltaTimeSeconds() const
{
    float time = std::chrono::duration_cast<std::chrono::milliseconds>(_actualUpdate - _lastUpdate).count();
    float result = time / 1000;
    return result;
}

int64_t Clock::getDeltaTimeMilliseconds() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(_actualUpdate - _lastUpdate).count();
}