# Class SparseArray

La classe `SparseArray` est une structure de données permettant de stocker un tableau de données optionnelles. Elle est utilisée dans le moteur de jeu R-type pour gérer les composants de manière efficace.

## Utilisation

La classe `SparseArray` est un conteneur générique conçu pour stocker des données de type `Component`. Elle fournit un ensemble de méthodes pour accéder, insérer, supprimer et rechercher des éléments dans le tableau.

## Constructeur

La classe `SparseArray` possède un constructeur par défaut, un constructeur de copie, un constructeur de déplacement et un destructeur.

## Opérateurs

- `operator[]`: Permet d'accéder à un élément du tableau par son index. Si l'index est supérieur à la taille actuelle du tableau, un élément vide de type `Component` est renvoyé.

## Méthodes

- `begin`, `end`, `cbegin`, `cend`: Permettent de parcourir le tableau à l'aide d'itérateurs.
- `size`: Retourne la taille actuelle du tableau.
- `insert_at`: Insère un élément de type `Component` à une position donnée dans le tableau.
- `erase`: Supprime un élément à une position donnée dans le tableau.
- `get_index`: Retourne l'index d'un élément dans le tableau.

## Exemple d'utilisation

```cpp
// Création d'un SparseArray de composants
RNGine::SparseArray<Component> sparseArray;

// Insertion d'un composant à l'index 3
Component comp;
sparseArray.insert_at(3, comp);

// Accès à un composant à l'index 1
Component retrievedComp = *sparseArray[1];
```