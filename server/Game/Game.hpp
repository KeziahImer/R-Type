/*
** EPITECH PROJECT, 2023
** R-Type [WSL: Ubuntu]
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

class Game
{
public:
    Game() = default;
    ~Game() = default;
    int getNbPlayers(void);
    int addPlayer(void);

private:
    int _nbPlayers = 0;
    int _maxPlayers = 4;
};

#endif /* !GAME_HPP_ */
