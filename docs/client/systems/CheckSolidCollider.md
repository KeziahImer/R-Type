# CheckSolidCollider
Le système "CheckSolidCollider" est responsable de la gestion des collisions entre les entités solides dans le jeu. Il permet de détecter et de gérer les collisions entre les entités solides, en appliquant des réponses appropriées en fonction des types de collisions.

Ce système est essentiel pour la physique du jeu, en permettant aux entités solides d'interagir correctement les unes avec les autres. Il prend en charge des actions telles que la réflexion, la suppression d'entités, ou l'application de forces de poussée.

## Fonctionnalités
Le système "CheckSolidCollider" effectue les actions suivantes :
- Détecte les collisions entre les entités solides.
- Gère la réaction aux collisions en appliquant des forces de poussée ou en faisant exploser des entités.
- Contribue à la physique du jeu en permettant aux entités solides d'interagir.

## Exemple d'utilisation
Le système "CheckSolidCollider" est utilisé pour gérer les collisions entre les entités solides dans le jeu :

```cpp
// Utilisation du système CheckSolidCollider
Client::Systems::CheckSolidCollider(core);
```