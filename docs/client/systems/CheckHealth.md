# CheckHealth
Le système "CheckHealth" est responsable de la gestion de la santé des entités dans le jeu. Il vérifie la santé des entités attaquables (objets ou ennemis) et prend des mesures en cas de santé nulle ou inférieure. Il gère la disparition des entités, génère des objets de butin et prend en compte les conditions de victoire ou de défaite.

Ce système vérifie la santé des composants "Attackable" (RNGine::Components::Attackable) et prend des mesures en fonction de la santé actuelle. Il génère des objets de butin, déclenche des animations d'explosion, gère le passage à l'écran de défaite ou de victoire, et supprime les entités détruites.

## Fonctionnalités
Le système "CheckHealth" effectue les actions suivantes :
- Vérifie la santé des entités attaquables.
- Gère la génération d'objets de butin en fonction de la santé nulle ou inférieure.
- Déclenche des animations d'explosion lorsque des entités sont détruites.
- Gère le passage à l'écran de défaite ou de victoire en fonction des conditions de jeu.
- Supprime les entités qui n'ont plus de santé.

## Exemple d'utilisation
Le système "CheckHealth" est utilisé pour gérer la santé et les interactions liées à la santé dans le jeu :

```cpp
// Utilisation du système CheckHealth
Client::Systems::CheckHealth(core);
```