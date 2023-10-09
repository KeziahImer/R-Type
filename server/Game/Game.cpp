/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Game
*/

#include "Game.hpp"

int Game::getNbPlayers(void)
{
    return _nbPlayers;
}

int Game::addPlayer(void)
{
    if (_nbPlayers < _maxPlayers)
    {
        _nbPlayers += 1;
        return 0;
    }
    return -1;
}
