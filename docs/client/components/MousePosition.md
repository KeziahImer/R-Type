# Composant "MousePosition"

Le composant "MousePosition" est utilisé pour stocker les informations liées à la position de la souris dans le jeu. Il permet de suivre la position de la souris, ainsi que l'état des boutons gauche et droit de la souris. Ce composant stocke les informations suivantes :

- `position`: Un objet de type r::Vector2 représentant la position actuelle de la souris dans le jeu (coordonnées x et y).


- `right_click`: Un booléen indiquant si le bouton droit de la souris est enfoncé (true) ou non (false).


- `left_click`: Un booléen indiquant si le bouton gauche de la souris est enfoncé (true) ou non (false).


Ce composant est essentiel pour interagir avec des éléments du jeu qui dépendent de la position et des actions de la souris, comme des boutons, des menus, ou des éléments interactifs.

## Exemple d'utilisation
Le composant "MousePosition" est utilisé pour suivre la position de la souris et l'état des boutons de la souris dans le jeu :

```cpp
// Création d'un composant MousePosition
Client::Components::MousePosition mousePosition;
mousePosition.position.x = 100; // Position x de la souris
mousePosition.position.y = 200; // Position y de la souris
mousePosition.right_click = false; // Bouton droit de la souris non enfoncé
mousePosition.left_click = true; // Bouton gauche de la souris enfoncé

// Utilisation du composant MousePosition pour gérer l'interaction de la souris
```