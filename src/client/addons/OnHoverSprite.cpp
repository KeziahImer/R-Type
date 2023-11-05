
#include "addons/OnHoverSprite.hpp"
#include "addons/IsHover.hpp"
#include "components/MousePosition.hpp"

void Client::Components::OnHoverSpriteSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &textures = scene.GetComponents<Client::Components::RenderTexture>();
  auto &hoverSprites = scene.GetComponents<Client::Components::OnHoverSprite>();
  auto &isHovers = scene.GetComponents<Client::Components::IsHover>();

  auto max = hoverSprites.size();
  for (size_t i = 0; i < max; i++) {
    auto &texture = textures[i];
    auto &hoverSprite = hoverSprites[i];
    auto &isHover = isHovers[i];
    if (!hoverSprite.has_value() || !texture.has_value() ||
        !isHover.has_value())
      continue;

    if (isHover->isHover) {
      if (!hoverSprite->isChanged) {
        hoverSprite->tmpSprite = texture.value();
        texture = std::make_optional(hoverSprite->hoverSprite);
        hoverSprite->isChanged = true;
      }
    } else {
      if (hoverSprite->isChanged) {
        texture.swap(hoverSprite->tmpSprite);
        hoverSprite->isChanged = false;
      }
    }
  }
}
