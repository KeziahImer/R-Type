# Renderer

The "Renderer" module is responsible for rendering sprites in the game. It's responsible for displaying the game's graphical elements, such as characters, enemies, backgrounds, and other visual objects. This module uses the Raylib library to perform texture rendering.

Rendering is essential for players to visually experience and interact with the game.

## Features
The "Renderer" module performs the following actions:

- Renders sprites in the current scene using the "RenderTexture" components associated with entities.

- Updates sprites based on their position, transformation, and hitbox.

- Manages the textures used for rendering.

## Example Usage
The "Renderer" module is used to display sprites in the game:

```cpp
// Create an instance of Renderer
Client::Renderer renderer;

// Inside the game's main loop
while (!r::WindowShouldClose()) {
    // ...
    renderer.RenderSprites(core.GetActualScene()); // Display sprites of the current scene
    // ...
}
```