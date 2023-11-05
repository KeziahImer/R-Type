# Menus

## Boutons
Buttons are interactive elements that allow players to navigate the main menu. They are created using the CreateButton method. Each button has components such as Client::Components::IsHover and Client::Components::IsClicked to handle mouse interactions.

Example code for creating a button:
```cpp
CreateButton("solo", "./assets/menu/btn-solo", 0);
```

## Mouse Position Tracking
Mouse position tracking is managed by the TrackMousePositionSystem system. It updates the mouse entity's position based on the actual mouse position.

Example code for mouse position tracking:

```cpp
core.AddSystem("track-mouse-position", Client::Scenes::Home::TrackMousePositionSystem);
```

## Background
The scene's background consists of entities like "background1," "background2," "redmoon," and "greenmoon." These entities are created with background textures and are animated to create a parallax effect.

Example code for creating a background:

```cpp
CreateEntity("background1");
scene.AddComponent<Client::Components::RenderTexture>(
    background1,
    {"./assets/levels/space/space_background.png", -3, {0, 0, 514, 360}});
scene.AddComponent<RNGine::Components::Transform>(background1,
    {0, 0, 0, 3.73, 3});
scene.AddComponent<Client::Components::Parallax>(background1, {{-1920, 1920}});
scene.AddComponent(background1, RNGine::Addons::Velocity({-100, 0}));
```