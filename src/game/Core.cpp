/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game implementation
*/

#include "Rtype/Rtype.hpp"
#include <iostream>

void Rtype::Core::CreateShipFactory() {
  CreateEntity("ship-factory");
  AddComponent<Rtype::Addons::ShipFactory>("ship-factory", {});
}