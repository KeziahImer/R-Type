/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** CheckDamage
*/
#include "systems/CheckHealth.hpp"
#include "RNGine/addons/Collider.hpp"
#include "RNGine/components/Attackable.hpp"
#include "RNGine/components/Damages.hpp"
#include "RNGine/components/MakeDamage.hpp"
#include "RNGine/components/Score.hpp"
#include "RNGine/components/Transform.hpp"
#include "Rtype/addons/IsLoot.hpp"
#include "Rtype/addons/LootableEntity.hpp"
#include "Rtype/addons/ShipController.hpp"
#include "Rtype/addons/WinCondition.hpp"
#include "addons/SpriteAnimation.hpp"
#include "components/SoundComponent.hpp"
#include <iostream>
#include <random>

void Client::Systems::CheckHealth(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &Attackables = scene.GetComponents<RNGine::Components::Attackable>();
  auto &loots = scene.GetComponents<Rtype::Components::LootableEntity>();
  auto &winConditions = scene.GetComponents<Rtype::Components::WinCondition>();
  auto &score = scene.GetComponents<RNGine::Components::Score>();
  auto &damage = scene.GetComponents<RNGine::Components::Damages>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &ships = scene.GetComponents<RNGine::Components::Score>();

  for (size_t i = 0; i < Attackables.size(); i++) {
    if (!Attackables[i].has_value())
      continue;
    if (Attackables[i]->health <= 0) {
      if (loots[i].has_value() && transforms[i].has_value()) {
        std::random_device rd;
        std::mt19937 rng(rd());

        for (const auto &pair : loots[i]->lootChances) {
          float chance = pair.second;
          std::uniform_int_distribution<int> distribution(1, 100);
          int randomValue = distribution(rng);

          if (randomValue <= chance) {
            for (size_t x = 0; x < score.size(); x++) {
              if (!score[x].has_value())
                continue;
              if (pair.first == Rtype::Components::HEAL) {
                if (Attackables[i].has_value()) {
                  auto heal = scene.CreateEntity("heal");
                  scene.AddComponent<RNGine::Components::Transform>(
                      heal, {transforms[i]->x, transforms[i]->y, 0,
                             transforms[i]->scaleX, transforms[i]->scaleY});
                  scene.AddComponent(heal,
                                     RNGine::Components::Hitbox(
                                         {16 * transforms[i]->scaleX,
                                          15 * transforms[i]->scaleY, 0, 0}));
                  scene.AddComponent(heal, RNGine::Addons::Collider());
                  scene.AddComponent<Client::Components::RenderTexture>(
                      heal, {"./assets/healthLoot.png", 1, {0, 0, 16, 15}});
                  scene.AddComponent<Client::Components::SpriteAnimation>(
                      heal, {false, false, true, false,
                             std::make_pair<int, int>(0, 0),
                             std::make_pair<int, int>(4, 0),
                             std::make_pair<int, int>(4, 0), 200});
                  scene.AddComponent<Rtype::Addons::IsLoot>(
                      heal, {Rtype::Components::HEAL, 50});
                }
              }
              if (pair.first == Rtype::Components::ATTACKUP) {
                if (damage[x].has_value()) {
                  auto damageUp = scene.CreateEntity("heal");
                  scene.AddComponent<RNGine::Components::Transform>(
                      damageUp,
                      {transforms[i]->x, transforms[i]->y, 0, 0.2, 0.2});
                  scene.AddComponent(
                      damageUp,
                      RNGine::Components::Hitbox({480 * 0.2, 145 * 0.2, 0, 0}));
                  scene.AddComponent(damageUp, RNGine::Addons::Collider());
                  scene.AddComponent<Client::Components::RenderTexture>(
                      damageUp, {"./assets/level_up.png", 1, {0, 0, 480, 145}});
                  scene.AddComponent<Client::Components::SpriteAnimation>(
                      damageUp, {false, false, true, false,
                                 std::make_pair<int, int>(0, 0),
                                 std::make_pair<int, int>(2, 0),
                                 std::make_pair<int, int>(2, 0), 200});
                  scene.AddComponent<Rtype::Addons::IsLoot>(
                      damageUp, {Rtype::Components::ATTACKUP, 25});
                }
              }
            }
          }
        }
      }
      scene.AddComponent<Client::Components::SoundComponent>(
          i, {"./assets/sounds/explosion.wav", true, false, false});
      if (ships[i].has_value()) {
        core.SetActualScene("gameOver");
      }
      if (winConditions[i].has_value()) {
        core.SetActualScene("victory");
      }
      scene.RemoveEntity(i);
    }
  }
}
