# RenderTexture
Le composant "RenderTexture" est utilisé pour stocker des informations sur la texture à afficher ou à dessiner dans une scène du jeu. Il contient des données sur l'emplacement, les propriétés de transformation, la source, la destination et d'autres propriétés de la texture. Ce composant stocke les informations suivantes :

- path: Une chaîne de caractères représentant le chemin vers la texture à utiliser.
- `z`: Un entier représentant la profondeur de la texture dans la scène (pour le rendu en couches).


- `source`: Un rectangle (de type raylib Rectangle) spécifiant la zone de la texture source à dessiner.


- `dest`: Un rectangle (de type raylib Rectangle) spécifiant la zone de destination où la texture sera dessinée.


- `origin`: Un vecteur (de type raylib Vector2) spécifiant le point d'origine de la texture (pour la rotation ou le pivot).


- `rotation`: Un flottant représentant l'angle de rotation de la texture.


- `useTransformPropreties`: Un booléen indiquant si les propriétés de transformation doivent être utilisées pour dessiner la texture.


- `useHitboxPropreties`: Un booléen indiquant si les propriétés de la boîte de collision (hitbox) doivent être utilisées pour déterminer les collisions.



Ce composant est utilisé pour définir et gérer l'apparence et le comportement des textures dans le jeu. Il permet de spécifier la façon dont une texture est affichée, positionnée et transformée dans une scène.

## Exemple d'utilisation
Le composant "RenderTexture" est utilisé pour définir les propriétés d'une texture dans une scène du jeu :

```cpp
// Création d'un composant RenderTexture
Client::Components::RenderTexture texture;
texture.path = "path_to_texture.png";
texture.z = 1;
texture.source = r::Rectangle{0, 0, 64, 64};
texture.dest = r::Rectangle{100, 100, 64, 64};
texture.origin = r::Vector2{32, 32};
texture.rotation = 45.0f;
texture.useTransformPropreties = true;
texture.useHitboxPropreties = true;

// Utilisation du composant RenderTexture pour afficher ou dessiner la texture dans la scène
```