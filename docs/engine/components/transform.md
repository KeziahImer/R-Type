# Composant "Transform"

The "Transform" component is used to define the spatial transformation of a game entity. It stores the following information:

- `x`: The position x.


- `y`: The position y.


- `rotation`: The rotation of the entity (in degrees).


- `scaleX`: The scale in the x-axis of the entity.


- `scaleY`:  The scale in the y-axis of the entity.



The "Transform" component allows you to position, orient, and resize an entity within the game world.
## Exemple d'utilisation

```cpp
RNGine::Components::Transform transform;
transform.x = 100;
transform.y = 200;
transform.rotation = 45; // 45-degree rotation
transform.scaleX = 1.5; // Scale in the x-axis of 1.5
transform.scaleY = 1.5; // Scale in the y-axis of 1.5

// Using the Transform component to position, orient, and resize an entity.
```