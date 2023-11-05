# IsHover

The "IsHover" addon is used to record whether an entity is currently being hovered over by the mouse cursor. It stores the following value:

- `isHover`: A boolean indicating whether the entity is currently being hovered over by the mouse cursor.

This component is used to handle mouse hover interactions with game entities. The associated "IsHoverSystem" checks if the mouse cursor is inside the collision area of the entity using the "Hitbox" and "Transform" components. It updates the "isHover" value accordingly.

## Example Usage

The "IsHover" component is updated by the "IsHoverSystem" to reflect whether an entity is currently being hovered over by the mouse cursor.

```cpp
// Creating an IsHover component
Client::Components::IsHover isHover;

// Using the IsHover component to check if the entity is being hovered over
if (isHover.isHover) {
    // Perform an action when the entity is being hovered over
}
```


