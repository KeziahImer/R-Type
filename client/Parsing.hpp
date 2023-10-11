/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** parsing
*/

#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <string>

static const std::string DIRECTORY_PATH = "./scenes";
using json = nlohmann::json;

class Parsing
{
public:
  Parsing();
  ~Parsing();
  void pushJsonData(const std::string &filename);
  void parseJsonFiles();
  json getJsonData(const std::string &filename);
  std::map<std::string, json> getAllData();

protected:
private:
  std::map<std::string, json> _allData;
};
