# SetMousePosition
Le module "SetMousePosition" est responsable de la mise à jour de la position de la souris dans le moteur de jeu. Il permet de suivre et de mettre à jour en temps réel les coordonnées de la souris, ainsi que de vérifier si les boutons gauche et droit de la souris sont enfoncés.

Ce module est essentiel pour gérer les interactions utilisateur-souris, notamment pour détecter les clics de souris et suivre la position de la souris.

## Fonctionnalités
Le module "SetMousePosition" effectue les actions suivantes :

- `r::GetMousePosition()`: Récupère les coordonnées actuelles de la souris.


- `r::IsMouseButtonPressed(r::MOUSE_LEFT_BUTTON)`,`r::IsMouseButtonPressed(r::MOUSE_RIGHT_BUTTON)`: Vérifie si les boutons gauche et droit de la souris sont enfoncés.


- Met à jour les composants de position de la souris associés à la scène du jeu avec les informations actuelles de la souris.


## Exemple d'utilisation
Le module "SetMousePosition" est utilisé pour mettre à jour la position de la souris dans le jeu. Voici comment vous pouvez l'utiliser dans la boucle principale du jeu :

```cpp
// Exemple d'utilisation dans la boucle principale du jeu
while (!r::WindowShouldClose()) {
    // ...
    SetMousePosition(scene); // Met à jour la position de la souris
    // ...
}
```