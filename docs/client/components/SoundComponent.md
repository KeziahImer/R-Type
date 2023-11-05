# SoundComponent Component

The "SoundComponent" component is used to manage the playback of audio files (sounds) in the game. It allows specifying an audio file to play, controlling playback, looping, and volume of the sound. This component is primarily used for adding sound effects or music to the game.

This component includes the following information:

- 
- `path`: A string representing the path of the audio file to be played. This can be an audio file in WAV, MP3, or other formats.


- `play`: A boolean indicator specifying whether the sound should be played (true) or not (false).


- `loop`: A boolean indicator specifying whether the sound should be played in a loop (true) or not (false).


- `stop`: A boolean indicator specifying whether the sound should be stopped (true) or not (false).


- `volume`: A floating-point number representing the volume of the sound (from 0 to 100, with 100 being the maximum volume).
This component allows for controlling the playback of audio files in the game by specifying the file to play, whether it should loop, its volume, and whether it should be stopped. It is used to add sound effects and music to the game, enhancing the players' audio experience.

## Example Usage

The "SoundComponent" component is used to manage the playback of audio files in the game:

```cpp
// Creating a SoundComponent component
Client::Components::SoundComponent sound;

// Specifying the path of the audio file
sound.path = "audio/mysound.wav";

// Playing the sound
sound.play = true;

// Adjusting the volume
sound.volume = 50; // Setting the volume to 50%

// Looping the sound
sound.loop = true;

// Stopping the playback
sound.stop = false;

// Using the SoundComponent component to manage audio playback
```