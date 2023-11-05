#include "addons/SpriteAnimation.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "addons/IsHover.hpp"
#include "addons/OnHoverSprite.hpp"
#include "components/MousePosition.hpp"
#include <iostream>

void Client::Components::SpriteAnimationSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &textures = scene.GetComponents<Client::Components::RenderTexture>();
  auto &animations = scene.GetComponents<Client::Components::SpriteAnimation>();

  auto max = animations.size();
  for (size_t i = 0; i < max; i++) {
    auto &texture = textures[i];
    auto &animation = animations[i];
    auto currentTime = core.deltaTime;
    if (!texture.has_value() || !animation.has_value())
      continue;
    if (animation->finish)
      continue;
    animation->lastUpdate = animation->lastUpdate + currentTime;
    if (animation->lastUpdate < animation->frequence / 1000)
      continue;
    animation->lastUpdate = 0;
    auto width = texture->source.width;
    auto height = texture->source.height;
    auto actualTile = (int)(texture->source.x / texture->source.width);
    if (!animation->multiple) {
      if (actualTile >= animation->end.first && !animation->reverse) {
        animation->finish = true;
        texture->source.x = animation->lastFrame.first * width;
        continue;
      }
      if (actualTile <= animation->start.first && animation->reverse) {
        animation->finish = true;
        texture->source.x = animation->lastFrame.first * width;
        continue;
      }
    }
    if (animation->loop) {
      if (actualTile >= animation->end.first && !animation->reverse)
        animation->reverse = !animation->reverse;
      if (actualTile <= animation->start.first && animation->reverse)
        animation->reverse = !animation->reverse;
    }
    if (!animation->reverse) {
      if (actualTile >= animation->end.first) {
        texture->source.x = animation->start.first * width;
      } else {
        texture->source.x += width;
      }
    } else {
      if (actualTile <= animation->start.first) {
        texture->source.x = animation->end.first * width;
      } else {
        texture->source.x -= width;
      }
    }
  }
}
