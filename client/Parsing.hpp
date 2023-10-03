/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** parsing
*/

#pragma once
    #include <map>
    #include <string>
    #include <iostream>
    #include <fstream>
    #include <filesystem>
    #include <nlohmann/json.hpp>

    static const std::string DIRECTORY_PATH = "./scenes";
    using json = nlohmann::json;

class Parsing {
    public:
        Parsing();
        ~Parsing();
        void pushJsonData(const std::string &filename);
        void parseJsonFiles();
        std::map<std::string, json> getAllData();

    protected:
    private:
        std::map<std::string, json> _allData;
};
