# Composant Hitbox
The "Hitbox" component is used to define a rectangular collision area associated with a game entity. It stores the following information:

- `width`: The width of the hitbox.


- `height`: The height of the hitbox.


- `originX`: The x-position of the origin point of the hitbox.


- `originY`: The y-position of the origin point of the hitbox.



The "Hitbox" component is crucial for detecting collisions between entities in the game. By using the dimensions and origin point of the collision box, it is possible to efficiently calculate collisions.


## Example of use

```cpp
RNGine::Components::Hitbox hitbox;
hitbox.width = 32;
hitbox.height = 32;
hitbox.originX = 16;
hitbox.originY = 16;
```