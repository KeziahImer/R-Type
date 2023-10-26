#include <algorithm>
#include <iostream>
#include <vector>

#include "Renderer.hpp"

void Client::Renderer::RenderSprites(RNGine::Scene &scene) {
  BeginDrawing();

  ClearBackground(BLACK);

  auto &textures = scene.GetComponents<Client::Components::RenderTexture>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &hitboxes = scene.GetComponents<RNGine::Components::Hitbox>();

  size_t max = textures.size();
  std::vector<Client::Components::RenderTexture> renders;
  for (size_t i = 0; i < max; i++) {
    auto &texture = textures[i];
    if (!texture.has_value())
      continue;
    if (_textures.find(texture->path) == _textures.end()) {
      _textures[texture->path] = LoadTexture(texture->path.c_str());
    }

    auto &transform = transforms[i];
    if (transform.has_value())
      UpdateSpriteWithTransform(texture.value(), transform.value());

    auto &hitbox = hitboxes[i];
    if (hitbox.has_value())
      UpdateSpriteWithHitbox(texture.value(), hitbox.value());
    renders.push_back(texture.value());
  }

  std::sort(renders.begin(), renders.end(), Client::Renderer::SortSpritesByZ);

  for (auto render : renders) {
    DrawTexturePro(_textures[render.path], render.source, render.dest,
                   render.origin, render.rotation, WHITE);
  }

  EndDrawing();
}

void Client::Renderer::UpdateSpriteWithTransform(
    Client::Components::RenderTexture &sprite,
    RNGine::Components::Transform &transform) {
  if (sprite.useTransformPropreties) {
    sprite.dest.x = transform.x;
    sprite.dest.y = transform.y;
    sprite.dest.width = sprite.source.width * transform.scaleX;
    sprite.dest.height = sprite.source.height * transform.scaleY;
    sprite.rotation = transform.rotation;
  }
}

void Client::Renderer::UpdateSpriteWithHitbox(
    Client::Components::RenderTexture &sprite,
    RNGine::Components::Hitbox &hitbox) {
  if (sprite.useHitboxPropreties) {
    sprite.origin.x = hitbox.originX;
    sprite.origin.y = hitbox.originY;
  }
  if (IsKeyDown(KEY_H)) {
    DrawRectangleLines(sprite.dest.x - sprite.origin.x,
                       sprite.dest.y - sprite.origin.y, hitbox.width,
                       hitbox.height, RED);
  }
}

bool Client::Renderer::SortSpritesByZ(
    const Client::Components::RenderTexture &a,
    const Client::Components::RenderTexture &b) {
  return a.z < b.z;
}
