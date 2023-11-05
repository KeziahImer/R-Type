#include "addons/ShipAnimation.hpp"
#include "addons/SpriteAnimation.hpp"

void Client::Addons::ShipAnimationSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &controller = scene.GetComponents<Rtype::Addons::ShipController>();
  auto &animations = scene.GetComponents<Client::Addons::ShipAnimation>();

  auto max = controller.size();
  for (size_t i = 0; i < max; i++) {
    auto &control = controller[i];
    auto &animation = animations[i];
    if (!control.has_value() || !animation.has_value())
      continue;
    if (control->movingUp) {
      if (animation->lastAction == Client::Addons::ShipAnimation::None) {
        scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, false, false, std::make_pair<int, int>(2, 2),
          std::make_pair<int, int>(4, 2), std::make_pair<int, int>(4, 2), 100});
        animation->lastAction = Client::Addons::ShipAnimation::Up;
      }
      if (animation->lastAction == Client::Addons::ShipAnimation::Down) {
        scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, false, false, std::make_pair<int, int>(0, 2),
          std::make_pair<int, int>(4, 2), std::make_pair<int, int>(4, 2), 100});
        animation->lastAction = Client::Addons::ShipAnimation::Up;
      }
    }
    if (control->movingDown) {
      if (animation->lastAction == Client::Addons::ShipAnimation::Up) {
        scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, false, false, std::make_pair<int, int>(4, 2),
          std::make_pair<int, int>(0, 2), std::make_pair<int, int>(0, 2), 100});
        animation->lastAction = Client::Addons::ShipAnimation::Down;
      }
      if (animation->lastAction == Client::Addons::ShipAnimation::None) {
        scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, false, false, std::make_pair<int, int>(2, 2),
          std::make_pair<int, int>(0, 2), std::make_pair<int, int>(0, 2), 100});
        animation->lastAction = Client::Addons::ShipAnimation::Down;
      }
    }
    if (!control->movingDown && !control->movingUp) {
      if (animation->lastAction == Client::Addons::ShipAnimation::Up) {
        scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, false, false, std::make_pair<int, int>(4, 2),
          std::make_pair<int, int>(2, 2), std::make_pair<int, int>(2, 2), 100});
        animation->lastAction = Client::Addons::ShipAnimation::None;
      }
      if (animation->lastAction == Client::Addons::ShipAnimation::Down) {
        scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, false, false, std::make_pair<int, int>(0, 2),
          std::make_pair<int, int>(2, 2), std::make_pair<int, int>(2, 2), 100});
        animation->lastAction = Client::Addons::ShipAnimation::None;
      }
    }
  }
}
