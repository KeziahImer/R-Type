/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Systems
*/

#pragma once

#include "include/GameEngine/ECS.hpp"
#include "include/components/Components.hpp"

class Systems {
    public:
        Systems();
        ~Systems();

        void checkMovable(GameEngine::Registry &registry);
        void checkVelocity(GameEngine::Registry &registry);
        void checkShoot(GameEngine::Registry &registry);
        void destroyOutScreenEntity(GameEngine::Registry &registry);

    protected:
    private:
};

