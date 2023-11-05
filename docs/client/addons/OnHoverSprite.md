# OnHoverSprite

The "OnHoverSprite" addon is used to manage the change of an entity's image or sprite when it is hovered over by the mouse cursor. It stores the following information:

- `hoverSprite`: The image or sprite that will be displayed when the entity is hovered over.

- `isChanged`: A boolean indicating whether the displayed image has been changed due to hovering.

- `hitbox`: A collision area associated with the entity (defined by a 4D vector).

- `tmpSprite`: The original image or sprite before hovering.

This component allows for the visual appearance of an entity to be modified when it is hovered over by the mouse cursor. The associated "OnHoverSpriteSystem" manages the image change based on entity hovering.

## Example Usage

The "OnHoverSprite" component is updated by the "OnHoverSpriteSystem" to handle image or sprite changes when the entity is hovered over.

```cpp
// Creating an OnHoverSprite component
Client::Components::OnHoverSprite onHoverSprite;

// Using the OnHoverSprite component to manage image changes when hovered
if (onHoverSprite.isChanged) {
    // Display the image or sprite associated with hovering
} else {
    // Display the original image or sprite
}
```