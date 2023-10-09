/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Paquet
*/

#ifndef PAQUET_HPP_
#define PAQUET_HPP_

#include <iostream>

class Paquet
{
public:
    Paquet(const double &time, const std::string &data);
    ~Paquet() = default;

private:
    std::string _data;
    char _buffer[1024];
    double _time;
    std::size_t _maxLength = 1024;
};

#endif /* !PAQUET_HPP_ */
