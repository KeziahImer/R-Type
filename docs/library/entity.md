# Gestion des Entités (Entities)

Dans notre jeu R-Type, les entités jouent un rôle central. Les entités représentent les objets du monde du jeu, tels que les vaisseaux spatiaux, les ennemis, les projectiles et divers autres éléments interactifs. Comprendre comment les entités sont gérées est essentiel pour tout développeur travaillant sur notre jeu.

## Création des Entités

Les entités sont créées de manière dynamique pendant le jeu. Chaque entité est associée à un identifiant unique et est composée de plusieurs composants qui définissent ses caractéristiques.

### Exemple de Création d'une Entité :

```cpp
createPlayer(createEntity("player")); 
addComponent(e, RNGine::components::Position::createPosition(x, y));
addComponent(e, RNGine::components::Size::createSize(scaleWidth, scaleHeight));
```
## Utilisation des Entités

Les entités sont mises à jour et gérées par les systèmes de l'architecture ECS. Les systèmes agissent sur les entités en fonction des composants associés.

### Exemple d'Utilisation des Entités :

```cpp
RNGine::Entity Registry::getEntity(std::string const &name) {
    auto it = _entities.find(name);
    if (it != _entities.end()) {
        return it->second;
    }
    throw std::runtime_error("Entity not found in registry.");
}
```

## Destruction des Entités

Les entités peuvent être détruites lorsqu'elles ne sont plus nécessaires. Les composants associés sont retirés, libérant ainsi des ressources.

### Exemple de Destruction d'une Entité :

```cpp
void Registry::removeEntity(RNGine::Entity entity) {
    for (auto remove : _removes) {
        remove.second(*this, entity);
    }
}
```

## Interaction entre Entités

Les entités peuvent interagir les unes avec les autres, par exemple, les projectiles peuvent infliger des dégâts à d'autres entités. Cette interaction est gérée par les systèmes et les événements au sein du jeu.

## Résumé
La gestion 
des entités est un élément clé de l'architecture ECS de notre jeu R-Type. Les entités sont créées dynamiquement, mises à jour par les systèmes et potentiellement détruites au cours du jeu. Elles constituent la base de l'expérience de jeu et sont essentielles pour créer un monde interactif et dynamique.