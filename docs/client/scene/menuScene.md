# Fonctionnement des menus

## Boutons
Les boutons sont des éléments interactifs qui permettent au joueur de naviguer dans le menu principal. Ils sont créés à l'aide de la méthode `CreateButton`. Chaque bouton a des composants tels que `Client::Components::IsHover` et `Client::Components::IsClicked` pour gérer les interactions de la souris.

Exemple de code pour la création d'un bouton :
```cpp
CreateButton("solo", "./assets/menu/btn-solo", 0);
```

## Suivi de la position de la souris
Le suivi de la position de la souris est géré par le système `TrackMousePositionSystem`. Il permet de mettre à jour la position de l'entité de la souris en fonction de la position réelle de la souris.

Exemple de code pour le suivi de la position de la souris :

```cpp
core.AddSystem("track-mouse-position", Client::Scenes::Home::TrackMousePositionSystem);
```

## Fond d'écran
Le fond d'écran de la scène est constitué d'entités telles que "background1", "background2", "redmoon" et "greenmoon". Ces entités sont créées avec des textures de fond et sont animées pour créer un effet de parallaxe.

Exemple de code pour la création d'un fond d'écran :

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