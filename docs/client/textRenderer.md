# TextRenderer
Le module "TextRenderer" est responsable de l'affichage de texte à l'écran dans le jeu. Il permet de mettre à jour et d'afficher divers éléments de texte, tels que les scores, les niveaux, la vie des personnages, etc. Cela contribue à l'interface utilisateur du jeu en fournissant des informations essentielles aux joueurs.

L'affichage de texte est important pour communiquer des informations aux joueurs et pour créer une interface utilisateur informative et intuitive.

## Fonctionnalités
Le module "TextRenderer" effectue les actions suivantes :

- Affiche le score du joueur.


- Affiche la vie des personnages ou des objets.


- Affiche le niveau en cours.


- Gère la mise à jour et l'affichage de divers éléments de texte.


## Exemple d'utilisation
Le module "TextRenderer" est utilisé pour afficher du texte dans le jeu :

```cpp
// Création d'une instance de TextRenderer
Client::TextRenderer textRenderer;

// Dans la boucle principale du jeu
while (!r::WindowShouldClose()) {
    // ...
    textRenderer.UpdateTexts(core.GetActualScene()); // Met à jour et affiche le texte
    // ...
}
```