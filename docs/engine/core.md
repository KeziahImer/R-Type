# Class Core
## Constructeur

La classe `Core` dispose d'un constructeur qui initialise les attributs de base du moteur :

```cpp
Core();
```

- `currentTime`: L'heure actuelle du moteur.


- `nextUpdate`: L'heure prévue pour la prochaine mise à jour du jeu.


- `lastUpdate`: L'heure de la dernière mise à jour du jeu.


- `deltaTime`: La durée écoulée depuis la dernière mise à jour.


- `targetFPS`: La fréquence d'images cible du jeu (par défaut, 60 images par seconde).

## Méthode "Update"
La méthode Update est responsable de la mise à jour du moteur. Elle calcule le temps écoulé depuis la dernière mise à jour et détermine si le moteur doit être mis à jour à la prochaine étape :

```cpp
void update();
```
- `currentTime`: Met à jour l'heure actuelle.


- `nextUpdate`: Calcule le moment où la prochaine mise à jour doit avoir lieu.


- `deltaTime`: Calcule la durée écoulée depuis la dernière mise à jour.


- `RunSystems`: Appelle la fonction RunSystems pour exécuter les systèmes enregistrés.

La méthode `update` renvoie true si le moteur doit être mis à jour à la prochaine étape, sinon elle renvoie "false".

## Méthode "GetNow"

La méthode `GetNow` permet d'obtenir l'heure actuelle sous forme d'une valeur de type Time :

```cpp
Time getNow();
```

- Elle utilise la bibliothèque `<chrono>` pour obtenir l'heure actuelle en secondes.

## Gestion des Systèmes
La classe `Core` permet d'ajouter, de supprimer et d'exécuter des systèmes. Un système est une fonction qui effectue une opération spécifique dans le jeu.

- AddSystem : Permet d'ajouter un système au moteur en fournissant un nom unique et une fonction associée.
- RemoveSystem: Permet de supprimer un système du moteur en utilisant son nom.
- RunSystems: Exécute tous les systèmes enregistrés dans le moteur.

## Gestion des Scènes

Le moteur R-type gère plusieurs scènes de jeu. La classe Core permet d'ajouter, de supprimer et de définir la scène actuelle.

- `AddScene`: Permet d'ajouter une scène au moteur en fournissant un nom unique et une instance de la classe Scene.


- `RemoveScene`: Permet de supprimer une scène du moteur en utilisant son nom.


- `SetActualScene`: Définit la scène actuelle à afficher et à mettre à jour. 

## Accès aux Scènes

La classe Core permet d'accéder aux scènes par leur nom :

- GetScene: Permet d'obtenir une référence vers une scène à partir de son nom.
- GetActualScene: Permet d'obtenir une référence vers la scène actuellement active.

## Accès au Nom de la Scène Actuelle

La méthode `GetActualSceneName` permet d'obtenir le nom de la scène actuelle.

La classe `Core` est un composant essentiel du moteur R-type, garantissant la gestion du temps, des systèmes et des scènes, ce qui en fait un élément central du jeu.

C'est la base sur laquelle d'autres composants, tels que les addons et les systèmes, s'appuient pour fournir des fonctionnalités et une interactivité au jeu R-type.