# Main

## 1. Window and Sound Initialization:

- `r::InitWindow(1920, 1080, "Super Mega Rtype")` initializes a game window with a resolution of 1920x1080 pixels and sets its title.

- `r::InitAudioDevice()` initializes the audio system.

- `r::SetMasterVolume(100)` sets the main audio volume to 100%.

- `r::ToggleFullscreen()` toggles fullscreen mode.

- `r::DisableCursor()` disables the mouse cursor within the window.

## 2. Creation of Rendering, Sound, and Network Objects:

- `Client::Renderer` renderer is responsible for the game's graphical rendering.

- `Client::SoundRenderer` soundRenderer is used for managing sound effects.

- `Client::TextRenderer` textRenderer handles text display on the screen.

- `Client::Networker networker` is used for network communication.

## 3. RNGine Game Engine Initialization:

- `RNGine::Core` core initializes the main game engine.

- Different game scenes are created, such as "Home," "Game," "Level1," "Level2," etc., each associated with a specific scene class instance.

## 4. Adding Scenes and Systems:

- `core.AddScene(...)` adds the created scenes to the game engine.

- `core.AddSystem(...)` adds systems to the game engine to manage specific features.

## 5. Main Game Loop:

- A `while` loop checks if the window should be closed. As long as the window is not closed, the loop continues to run.

- Within the loop, `core.Update()` is called to update the entity states and execute systems.

- Next, the loop renders the current scene by calling `renderer.RenderSprites()`, updates sounds with `soundRenderer.UpdateSounds()`, displays text with `textRenderer.UpdateTexts()`, and manages mouse position with `Client::SetMousePosition()`.

- Finally, the loop updates network communication with `networker.Update()`.

## 6. Closing the Game:

- After exiting the main loop, the code closes the audio device with `r::CloseAudioDevice()`.

- Then, the game window is closed with `r::CloseWindow()`.

## 7. Return Value:

The `main` function returns 0 to indicate a normal program exit.
