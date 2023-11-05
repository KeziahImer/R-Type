#include <algorithm>
#include <iostream>
#include <vector>

#include "RNGine/components/SoundComponent.hpp"
#include "SoundRenderer.hpp"

void Client::SoundRenderer::UpdateSounds(RNGine::Scene &scene) {
  auto &sounds = scene.GetComponents<Client::Components::SoundComponent>();

  auto max = sounds.size();
  for (size_t i = 0; i < max; i++) {
    auto &sound = sounds[i];
    if (!sound.has_value())
      continue;
    auto _sound = _sounds.find(sound->path);
    if (_sound == _sounds.end())
      _sounds.insert({sound->path, r::LoadSound(sound->path.c_str())});
    _sound = _sounds.find(sound->path);
    if (sound->play) {
      r::SetSoundVolume(_sound->second, sound->volume / 100);
      r::PlaySound(_sound->second);
      sound->play = false;
    }
    if (sound->loop) {
      if (!r::IsSoundPlaying(_sound->second))
        r::PlaySound(_sound->second);
    }
    if (sound->stop) {
      if (!r::IsSoundPlaying(_sound->second))
        r::StopSound(_sound->second);
    }
  }
}
