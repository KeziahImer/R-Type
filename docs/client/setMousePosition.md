# SetMousePosition

The "SetMousePosition" module is responsible for updating the mouse position in the game engine. It allows real-time tracking and updating of the mouse coordinates and checking if the left and right mouse buttons are pressed.

This module is essential for managing user-mouse interactions, especially for detecting mouse clicks and tracking the mouse's position.

## Features
The "SetMousePosition" module performs the following actions:

- `r::GetMousePosition()`: Retrieves the current mouse coordinates.

- `r::IsMouseButtonPressed(r::MOUSE_LEFT_BUTTON)`, `r::IsMouseButtonPressed(r::MOUSE_RIGHT_BUTTON)`: Checks if the left and right mouse buttons are pressed.

- Updates the mouse position components associated with the game scene with the current mouse information.

## Example Usage
The "SetMousePosition" module is used to update the mouse's position in the game. Here's how you can use it in the game's main loop:

```cpp
// Example of usage in the main game loop
while (!r::WindowShouldClose()) {
    // ...
    SetMousePosition(scene); // Update the mouse position
    // ...
}
```