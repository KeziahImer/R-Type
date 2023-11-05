
#include "components/Parallax.hpp"

void Client::Components::ParallaxSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &parallaxComponents =
      scene.GetComponents<Client::Components::Parallax>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();

  auto max = parallaxComponents.size();
  for (size_t i = 0; i < max; i++) {
    auto &parallaxComponent = parallaxComponents[i];
    auto &transformComponent = transforms[i];
    if (!parallaxComponent.has_value() || !transformComponent.has_value())
      continue;

    if (transformComponent->x <= parallaxComponent->position.first) {
      transformComponent->x = parallaxComponent->position.second;
    }
  }
}
