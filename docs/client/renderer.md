# Renderer
Le module "Renderer" est responsable du rendu des sprites dans le jeu. Il permet d'afficher les éléments graphiques du jeu, tels que les personnages, les ennemis, les arrière-plans et d'autres objets visuels. Ce module utilise la bibliothèque Raylib pour effectuer le rendu des textures.

Le rendu est essentiel pour que le joueur puisse visualiser et interagir avec le jeu de manière graphique.

## Fonctionnalités
Le module "Renderer" effectue les actions suivantes :

- Rendu des sprites dans la scène actuelle en utilisant les composants "RenderTexture" associés aux entités.


- Mise à jour des sprites en fonction de leur position, transformation et hitbox.


- Gestion des textures utilisées pour le rendu.
## Exemple d'utilisation
Le module "Renderer" est utilisé pour afficher les sprites dans le jeu :

```cpp
// Création d'une instance de Renderer
Client::Renderer renderer;

// Dans la boucle principale du jeu
while (!r::WindowShouldClose()) {
    // ...
    renderer.RenderSprites(core.GetActualScene()); // Affiche les sprites de la scène actuelle
    // ...
}
```