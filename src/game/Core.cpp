/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game implementation
*/

#include "Rtype/Rtype.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include <iostream>

void Rtype::Core::CreateShipFactory() {
  CreateEntity("ship-factory");
  AddComponent<Rtype::Addons::ShipFactory>("ship-factory", {});
}

void Rtype::Core::CreateEnemyFactory() {
  CreateEntity("enemy-factory");
  AddComponent<Rtype::Addons::EnemyFactory>("enemy-factory", {});
}

void Rtype::Core::CreateCollisionFactory() {
  CreateEntity("collision-factory");
  AddComponent<Rtype::Addons::CollisionFactory>("collision-factory", {});
}