/*
** EPITECH PROJECT, 2023
** mirror
** File description:
** PrefabGenerator
*/

#include "PrefabGenerator.hpp"

PrefabGenerator::~PrefabGenerator()
{
}

void PrefabGenerator::loadPrefab(const std::string &type, const std::string &id)
{
    const std::string directory_path = DIRECTORY_PREFABS_PATH;

    for (const auto &entry :
         std::filesystem::directory_iterator(directory_path))
    {
        const std::string &filename = entry.path().string();

        if (std::filesystem::is_regular_file(entry) &&
            filename.substr(filename.find_last_of(".") + 1) == "json")
        {
            std::string prefabName = filename.substr(filename.find_last_of("/") + 1, filename.find_last_of(".") - filename.find_last_of("/") - 1);
            if (prefabName == type)
            {
                std::string entityId = id;
                json data = _parser.getJsonData(filename);

                _factory.createAllComponents("prefab", data, type, id);
            }
        }
    }
}
