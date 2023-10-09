/*
** EPITECH PROJECT, 2023
** mirror
** File description:
** PrefabGenerator
*/

#ifndef PREFABGENERATOR_HPP_
#define PREFABGENERATOR_HPP_
#include "../ComponentFactory.hpp"
#include "../Parsing.hpp"
static const std::string DIRECTORY_PREFABS_PATH = "./prefabs";

class PrefabGenerator
{
public:
    PrefabGenerator(ComponentFactory &factory, GameEngine::Registry &registry, Parsing &parser) : _factory(factory), _registry(registry), _parser(parser) {}
    ~PrefabGenerator();
    void loadPrefab(const std::string &type, const std::string &id);

protected:
private:
    GameEngine::Registry &_registry;
    ComponentFactory &_factory;
    Parsing &_parser;
};

#endif /* !PREFABGENERATOR_HPP_ */
