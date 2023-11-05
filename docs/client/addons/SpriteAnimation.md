# SpriteAnimation
L'Addons "SpriteAnimation" est utilisé pour gérer les animations de sprites dans le jeu. Il permet de créer des animations en faisant défiler les images d'une texture à des intervalles réguliers. Ce composant stocke les informations suivantes :

- `reverse`: Un booléen indiquant si l'animation doit être inversée (true) ou non (false).



- `loop`: Un booléen indiquant si l'animation doit se répéter en boucle (true) ou s'arrêter après une seule itération (false).


- `multiple`: Un booléen indiquant si l'animation comporte plusieurs séquences d'images (true) ou une seule séquence (false).


- `finish`: Un booléen indiquant si l'animation a atteint sa fin (true) ou est en cours (false).


- `start`: Une paire d'entiers (x, y) représentant la première image de l'animation.


- `end`: Une paire d'entiers (x, y) représentant la dernière image de l'animation.


- `lastFrame`: Une paire d'entiers (x, y) représentant la dernière image affichée.


- `frequence`: Le temps en millisecondes entre chaque changement d'image de l'animation.


- `lastUpdate`: Le temps en millisecondes depuis la dernière mise à jour de l'animation.


Le système associé "SpriteAnimationSystem" gère la mise à jour des animations des sprites en fonction du temps et des paramètres définis dans ce composant.

## Exemple d'utilisation
Le composant "SpriteAnimation" est utilisé pour créer des animations de sprites dans le jeu :

```cpp
// Création d'un composant SpriteAnimation
Client::Components::SpriteAnimation animation;
animation.reverse = false; // L'animation n'est pas inversée
animation.loop = true; // L'animation se répète en boucle
animation.multiple = true; // L'animation comporte plusieurs séquences d'images
animation.finish = false; // L'animation est en cours
animation.start = std::make_pair(0, 0); // Première image de l'animation
animation.end = std::make_pair(3, 3); // Dernière image de l'animation
animation.lastFrame = std::make_pair(0, 0); // Dernière image affichée
animation.frequence = 100; // Changement d'image toutes les 100 millisecondes
animation.lastUpdate = 0; // Temps écoulé depuis la dernière mise à jour

// Utilisation du composant SpriteAnimation pour gérer une animation de sprite
```