# IsClicked

The "IsClicked" addon is used to record whether an entity has been clicked with the left or right mouse button. It stores the following information:

- `IsClickedRight`: A boolean indicating whether the entity has been clicked with the right mouse button.

- `IsClickedLeft`: A boolean indicating whether the entity has been clicked with the left mouse button.

This component is used to handle mouse click interactions with game entities. The associated "IsClickedSystem" updates these values based on information from the "IsHover" system and the "MousePosition" system.

## Example Usage

The "IsClicked" component is updated by the "IsClickedSystem," which checks whether an entity is currently hovering ("IsHover") and the position of the mouse cursor ("MousePosition"). If the entity is being hovered over and a mouse click is detected, the "IsClicked" component is updated accordingly.

```cpp
// Creating an IsClicked component
Client::Components::IsClicked isClicked;

// Using the IsClicked component to check if the entity has been clicked
if (isClicked.IsClickedLeft) {
    // Perform an action for a left click
}

if (isClicked.IsClickedRight) {
    // Perform an action for a right click
}
```