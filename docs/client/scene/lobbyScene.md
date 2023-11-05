# Fonctionnement du Lobby

## Introduction
La scène "Lobby" est une partie importante du jeu et contient plusieurs éléments de jeu essentiels. Cette documentation expliquera comment ces éléments fonctionnent dans le code.

## Boutons
Tout comme dans la scène "Home", la scène "Lobby" comporte également des boutons interactifs. Ces boutons sont créés à l'aide de la méthode `CreateButton`, et chaque bouton a des composants tels que `Client::Components::IsHover` et `Client::Components::IsClicked` pour gérer les interactions de la souris.

Exemple de code pour la création d'un bouton dans la scène "Lobby" :
```cpp
CreateButton("multiplayer", "./assets/menu/btn-start", r::GetScreenHeight() / 2);
```

## Suivi de la position de la souris
Le suivi de la position de la souris est géré par le système `TrackMousePositionSystem`. Il permet de mettre à jour la position de l'entité de la souris en fonction de la position réelle de la souris.

Exemple de code pour le suivi de la position de la souris :

```cpp
core.AddSystem("track-mouse-position", Client::Scenes::Home::TrackMousePositionSystem);
```

## Affichage du nombre de joueurs
La scène "Lobby" affiche le nombre de joueurs connectés. Cela est géré à l'aide du système `renderPlayers`. Le nombre de joueurs est stocké dans un composant `Client::Components::NumberPlayers`.

Exemple de code pour l'affichage du nombre de joueurs :

```cpp
void Client::Scenes::Lobby::renderPlayers(RNGine::Core &core) {
  if (core.GetActualSceneName() != "lobby")
    return;
  auto &scene = core.GetActualScene();
  auto &numberPlayers =
      scene.GetComponents<Client::Components::NumberPlayers>()[scene.GetEntity(
          "numberPLayers")];
  if (!numberPlayers.has_value())
    return;
  std::string toPrint;
  if (numberPlayers->numberPlayers == 0) {
    toPrint = "Connecting...";
  } else {
    toPrint = "Players: " + std::to_string(numberPlayers->numberPlayers);
  }
  r::DrawText(toPrint.c_str(), r::GetScreenWidth() - 250, r::GetScreenHeight() - 50, 40,
           r::LIGHTGRAY);
}
```