# Parallax
Le composant "Parallax" est utilisé pour gérer les effets de parallaxe dans le jeu. La parallaxe est une technique d'animation graphique qui crée une illusion de profondeur en faisant défiler différents calques d'arrière-plan à des vitesses différentes. Ce composant stocke les informations suivantes :

- `position`: Une paire de valeurs (x, y) représentant la position de l'effet de parallaxe.

Le système associé "ParallaxSystem" gère la mise à jour de la position de l'effet de parallaxe en fonction de l'évolution du jeu, créant ainsi un effet visuel de défilement d'arrière-plan.

## Exemple d'utilisation
Le composant "Parallax" est utilisé pour créer des effets de parallaxe dans le jeu :

```cpp
// Création d'un composant Parallax
Client::Components::Parallax parallax;
parallax.position = {0, 0}; // Position initiale de l'effet de parallaxe

// Utilisation du composant Parallax pour gérer l'effet de parallaxe
```
