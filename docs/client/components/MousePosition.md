# Component "MousePosition"

The "MousePosition" component is used to store information related to the mouse's position in the game. It allows tracking the mouse's position as well as the state of the left and right mouse buttons. This component stores the following information:

- `position`: An object of type r::Vector2 representing the current mouse position in the game (x and y coordinates).


- `right_click`: A boolean indicating if the right mouse button is pressed (true) or not (false).


- `left_click`: A boolean indicating if the left mouse button is pressed (true) or not (false).

This component is essential for interacting with game elements that depend on the mouse's position and actions, such as buttons, menus, or interactive elements.

## Example Usage

The "MousePosition" component is used to track the mouse's position and the state of the mouse buttons in the game:

```cpp
// Creating a MousePosition component
Client::Components::MousePosition mousePosition;
mousePosition.position.x = 100; // Mouse's x position
mousePosition.position.y = 200; // Mouse's y position
mousePosition.right_click = false; // Right mouse button not pressed
mousePosition.left_click = true; // Left mouse button pressed

// Using the MousePosition component to manage mouse interaction
```