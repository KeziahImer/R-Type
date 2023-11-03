/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** CheckDamage
*/
#include "systems/CheckDamage.hpp"
#include "RNGine/addons/Collider.hpp"
#include "RNGine/components/Attackable.hpp"
#include "RNGine/components/MakeDamage.hpp"
#include "RNGine/components/Score.hpp"
#include <iostream>

void Client::Systems::CheckCollisionsDamage(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &Collisions = scene.GetComponents<RNGine::Addons::Collider>();
  auto &Attackables = scene.GetComponents<RNGine::Components::Attackable>();
  auto &MakeDamages = scene.GetComponents<RNGine::Components::MakeDamage>();
  auto &Scores = scene.GetComponents<RNGine::Components::Score>();

  for (size_t i = 0; i < Attackables.size(); i++) {
    for (size_t x = 0; x < MakeDamages.size(); x++) {
      if (!Collisions[i].has_value() || !MakeDamages[x].has_value() ||
          !Attackables[i].has_value())
        continue;
      bool isColliding = false;
      for (auto col : Collisions[i]->collisions) {
        if (col == x) {
          isColliding = true;
        }
      }
      if (!isColliding)
        continue;
      if (Attackables[i]->ally == MakeDamages[x]->ally)
        continue;
      if (!Attackables[i]->_Attackable)
        continue;
      Attackables[i]->health = Attackables[i]->health - MakeDamages[x]->Damage;
      Attackables[i]->_Attackable = false;
      Attackables[i]->lastShoot =
          std::chrono::duration_cast<std::chrono::milliseconds>(
              std::chrono::system_clock::now().time_since_epoch())
              .count();
      if (Scores[MakeDamages[x]->father].has_value() &&
          Attackables[i]->health <= 0) {
        Scores[MakeDamages[x]->father]->score =
            Scores[MakeDamages[x]->father]->score + Attackables[i]->points;
      }
      scene.RemoveEntity(x);
    }
  }
}
