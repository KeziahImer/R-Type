# RenderTexture Component

The "RenderTexture" component is used to store information about the texture to display or draw in a game scene. It contains data about the location, transformation properties, source, destination, and other texture properties. This component stores the following information:

- 
- `path`: A string representing the path to the texture to use.


- `z`: An integer representing the depth of the texture in the scene (for layering).


- `source`: A rectangle (of type raylib Rectangle) specifying the source area of the texture to draw.


- `dest`: A rectangle (of type raylib Rectangle) specifying the destination area where the texture will be drawn.


- `origin`: A vector (of type raylib Vector2) specifying the origin point of the texture (for rotation or pivot).


- `rotation`: A float representing the rotation angle of the texture.


- `useTransformProperties`: A boolean indicating whether transformation properties should be used to draw the texture.


- `useHitboxProperties`: A boolean indicating whether hitbox properties should be used to determine collisions.
This component is used to define and manage the appearance and behavior of textures in the game. It allows specifying how a texture is displayed, positioned, and transformed within a scene.

## Example Usage

The "RenderTexture" component is used to define the properties of a texture in a game scene:

```cpp
// Creating a RenderTexture component
Client::Components::RenderTexture texture;
texture.path = "path_to_texture.png";
texture.z = 1;
texture.source = r::Rectangle{0, 0, 64, 64};
texture.dest = r::Rectangle{100, 100, 64, 64};
texture.origin = r::Vector2{32, 32};
texture.rotation = 45.0f;
texture.useTransformProperties = true;
texture.useHitboxProperties = true;

// Using the RenderTexture component to display or draw the texture in the scene
```