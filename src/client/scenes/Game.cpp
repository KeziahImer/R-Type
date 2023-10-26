#include "scenes/Game.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "components/RenderTexture.hpp"
#include "raylib.h"
#include "scenes/Home.hpp"

#include <iostream>

Client::Scenes::Game::Game(RNGine::Core &core) {

  CreateShipFactory();

  core.AddSystem("create-ship-factory", &Rtype::Addons::ShipFactorySystem);
  core.AddSystem("ship-controller", &Rtype::Addons::ShipControllerSystem);
  core.AddSystem("acceleration", &RNGine::Addons::AccelerationSystem);
  core.AddSystem("velocity", &RNGine::Addons::VelocitySystem);
  core.AddSystem("limits", &RNGine::Addons::LimitsSystem);
  core.AddSystem("collider", &RNGine::Addons::ColliderSystem);

  core.AddSystem("create-main-ship", &Client::Scenes::Game::CreateMainShip);
  core.AddSystem("apply-ship-texture", &Client::Scenes::Game::ApplyShipTexture);
  core.AddSystem("move-ship", &Client::Scenes::Game::MoveShip);
  core.AddSystem("set-bullets-texture",
                 &Client::Scenes::Game::SetBulletsTexture);
  core.AddSystem("leave-scene", &Client::Scenes::Game::LeaveScene);
}

void Client::Scenes::Game::CreateMainShip(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "game")
    return;
  auto &scene = core.GetActualScene();
  auto &factory =
      scene.GetComponents<Rtype::Addons::ShipFactory>()[scene.GetEntity(
          "ship-factory")];
  if (!factory.has_value())
    return;
  if (factory->ships.size() > 0)
    return;
  factory->creationRequests.push_back(
      Rtype::Addons::ShipCreationRequest({0, 100, 100}));
}

void Client::Scenes::Game::ApplyShipTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "game")
    return;
  auto &scene = core.GetActualScene();
  auto &ship =
      scene.GetComponents<Rtype::Addons::ShipController>()[scene.GetEntity(
          "ship-0")];
  if (!ship.has_value())
    return;
  auto e = scene.GetEntity("ship-0");
  auto alreadyExist =
      scene.GetComponents<Client::Components::RenderTexture>()[e];
  if (alreadyExist.has_value())
    return;
  scene.AddComponent<Client::Components::RenderTexture>(
      e, {"assets/ship.png", 10, {0, 0, 32, 14}});
}

void Client::Scenes::Game::MoveShip(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "game")
    return;
  auto &scene = core.GetActualScene();
  auto &ship =
      scene.GetComponents<Rtype::Addons::ShipController>()[scene.GetEntity(
          "ship-0")];
  if (!ship.has_value())
    return;
  if (IsKeyPressed(KEY_UP)) {
    ship->movingUp = true;
  }
  if (IsKeyReleased(KEY_UP)) {
    ship->movingUp = false;
  }
  if (IsKeyPressed(KEY_DOWN)) {
    ship->movingDown = true;
  }
  if (IsKeyReleased(KEY_DOWN)) {
    ship->movingDown = false;
  }
  if (IsKeyPressed(KEY_LEFT)) {
    ship->movingLeft = true;
  }
  if (IsKeyReleased(KEY_LEFT)) {
    ship->movingLeft = false;
  }
  if (IsKeyPressed(KEY_RIGHT)) {
    ship->movingRight = true;
  }
  if (IsKeyReleased(KEY_RIGHT)) {
    ship->movingRight = false;
  }
  if (IsKeyPressed(KEY_SPACE)) {
    ship->shooting = true;
  }
  if (IsKeyReleased(KEY_SPACE)) {
    ship->shooting = false;
  }
}

void Client::Scenes::Game::SetBulletsTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "game")
    return;
  auto &scene = core.GetActualScene();
  auto &ship =
      scene.GetComponents<Rtype::Addons::ShipController>()[scene.GetEntity(
          "ship-0")];
  if (!ship.has_value())
    return;

  auto &bullets = ship->bullets;

  auto &textures = scene.GetComponents<Client::Components::RenderTexture>();

  for (auto bullet : bullets) {
    auto &texture = textures[bullet];
    if (texture.has_value())
      continue;
    scene.AddComponent<Client::Components::RenderTexture>(
        bullet, {"./assets/bullet.png", 1, {0, 0, 32, 10}});
  }
}

void Client::Scenes::Game::LeaveScene(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "game")
    return;

  if (IsKeyReleased(KEY_BACKSPACE)) {
    core.AddScene("game", Client::Scenes::Game(core));
    core.SetActualScene("home");
  }
}
