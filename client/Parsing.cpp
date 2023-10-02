/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** parsing
*/

#include "Parsing.hpp"

Parsing::Parsing() {

}

Parsing::~Parsing() {
    
}

void Parsing::pushJsonData(const std::string &filename) {
    std::ifstream f(filename);
    json data = json::parse(f);

    if (data.is_object())
        _allData.emplace(filename, data);
    else
        std::cerr << "Le fichier JSON '" << filename << "' n'est pas un objet JSON valide." << std::endl;
}

std::map<std::string, json> Parsing::getAllData()
{
    return _allData;
}

void Parsing::parseJsonFiles() {
    const std::string directory_path = DIRECTORY_PATH;

    for (const auto &entry : std::filesystem::directory_iterator(directory_path)) {
        const std::string &filename = entry.path().string();

        if (std::filesystem::is_regular_file(entry) && filename.substr(filename.find_last_of(".") + 1) == "json") {
            std::cout << filename << std::endl;
            pushJsonData(filename);
        }
    }
}