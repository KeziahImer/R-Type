# NumberLevel
Le composant "NumberLevel" est utilisé pour stocker le numéro du niveau dans le jeu. Il permet de suivre le numéro du niveau actuel que le joueur est en train de jouer. Ce composant stocke l'information suivante :

- `numberLevel`: Un entier représentant le numéro du niveau actuel dans le jeu.

Ce composant est utile pour suivre et afficher le numéro du niveau que le joueur est en train de jouer, ce qui peut être utile dans l'interface utilisateur ou pour gérer la progression du jeu.

## Exemple d'utilisation
Le composant "NumberLevel" est utilisé pour suivre et afficher le numéro du niveau actuel :

```cpp
// Création d'un composant NumberLevel
Client::Components::NumberLevel level;
level.numberLevel = 1; // Le joueur joue actuellement au niveau 1

// Utilisation du composant NumberLevel pour afficher le numéro du niveau
```