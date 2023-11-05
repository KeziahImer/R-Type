# SoundRenderer

The "SoundRenderer" module is responsible for managing sound effects and music in the game. It allows loading, playing, pausing, and stopping audio files based on in-game events, creating an immersive auditory experience for the player.

Sound rendering is essential for adding a sensory dimension to the game by providing audio feedback in response to player actions and in-game events.

## Features
The "SoundRenderer" module performs the following actions:

- Loads audio files from specified paths.

- Plays sound effects or music based on signals received from the game scene.

- Manages the sound volume of audio files based on specified parameters.

- Pauses, resumes, and stops audio file playback as needed.

## Example Usage
The "SoundRenderer" module is used to manage sound effects and music in the game:

```cpp
// Creating an instance of SoundRenderer
Client::SoundRenderer soundRenderer;

// In the main game loop
while (!r::WindowShouldClose()) {
    // ...
    soundRenderer.UpdateSounds(core.GetActualScene()); // Manages sound effects and music
    // ...
}
```