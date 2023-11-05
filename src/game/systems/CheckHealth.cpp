/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** CheckDamage
*/
#include "Rtype/systems/CheckHealth.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Collider.hpp"
#include "RNGine/components/Attackable.hpp"
#include "RNGine/components/Damages.hpp"
#include "RNGine/components/Score.hpp"
#include "RNGine/components/SoundComponent.hpp"
#include "RNGine/components/Transform.hpp"
#include "Rtype/addons/IsLoot.hpp"
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/LootableEntity.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include "Rtype/addons/ShipController.hpp"
#include "Rtype/addons/WinConditionComponent.hpp"
#include <iostream>
#include <random>
#include <string>

void Client::Systems::CheckHealth(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &Attackables = scene.GetComponents<RNGine::Components::Attackable>();
  auto &loots = scene.GetComponents<Rtype::Components::LootableEntity>();
  auto &winConditions = scene.GetComponents<Rtype::Components::WinCondition>();
  auto &score = scene.GetComponents<RNGine::Components::Score>();
  auto &damage = scene.GetComponents<RNGine::Components::Damages>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &ships = scene.GetComponents<RNGine::Components::Score>();
  auto &isNetwork =
      scene.GetComponents<Rtype::Components::IsNetwork>()[scene.GetEntity(
          "network")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
  auto &sender =
      scene.GetComponents<Client::Components::SendPacket>()[scene.GetEntity(
          "sender")];

  for (size_t i = 0; i < Attackables.size(); i++) {
    if (!Attackables[i].has_value())
      continue;
    if (Attackables[i]->health <= 0) {
      if ((isNetwork.has_value() || networkId.has_value()) &&
          sender.has_value()) {
        if (scene.GetEntityName(i) == "") {
          std::cout << "Entity with empty name: " << i << std::endl;
        }
        sender->packets.push_back({"DEATH", scene.GetEntityName(i)});
      }
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
      scene.RemoveEntity(i);
    }
  }
}
