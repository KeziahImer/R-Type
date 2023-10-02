/*
** EPITECH PROJECT, 2023
** B-OOP-400-TLS-4-1-tekspice-simon.vermeulen [WSL : Ubuntu-18.04]
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

sf::Keyboard::Key mapStringToKeyboardKey(const std::string& keyString) {
    static const std::map<std::string, sf::Keyboard::Key> keyMap = {
        {"A", sf::Keyboard::A},
        {"B", sf::Keyboard::B},
        {"C", sf::Keyboard::C},
        {"D", sf::Keyboard::D},
        {"E", sf::Keyboard::E},
        {"F", sf::Keyboard::F},
        {"G", sf::Keyboard::G},
        {"H", sf::Keyboard::H},
        {"I", sf::Keyboard::I},
        {"J", sf::Keyboard::J},
        {"K", sf::Keyboard::K},
        {"L", sf::Keyboard::L},
        {"M", sf::Keyboard::M},
        {"N", sf::Keyboard::N},
        {"O", sf::Keyboard::O},
        {"P", sf::Keyboard::P},
        {"Q", sf::Keyboard::Q},
        {"R", sf::Keyboard::R},
        {"S", sf::Keyboard::S},
        {"T", sf::Keyboard::T},
        {"U", sf::Keyboard::U},
        {"V", sf::Keyboard::V},
        {"W", sf::Keyboard::W},
        {"X", sf::Keyboard::X},
        {"Y", sf::Keyboard::Y},
        {"Z", sf::Keyboard::Z},
        {"Num0", sf::Keyboard::Num0},
        {"Num1", sf::Keyboard::Num1},
        {"Num2", sf::Keyboard::Num2},
        {"Num3", sf::Keyboard::Num3},
        {"Num4", sf::Keyboard::Num4},
        {"Num5", sf::Keyboard::Num5},
        {"Num6", sf::Keyboard::Num6},
        {"Num7", sf::Keyboard::Num7},
        {"Num8", sf::Keyboard::Num8},
        {"Num9", sf::Keyboard::Num9},
        {"Escape", sf::Keyboard::Escape},
        {"LControl", sf::Keyboard::LControl},
        {"LShift", sf::Keyboard::LShift},
        {"LAlt", sf::Keyboard::LAlt},
        {"LSystem", sf::Keyboard::LSystem},
        {"RControl", sf::Keyboard::RControl},
        {"RShift", sf::Keyboard::RShift},
        {"RAlt", sf::Keyboard::RAlt},
        {"RSystem", sf::Keyboard::RSystem},
        {"Menu", sf::Keyboard::Menu},
        {"LBracket", sf::Keyboard::LBracket},
        {"RBracket", sf::Keyboard::RBracket},
        {"SemiColon", sf::Keyboard::SemiColon},
        {"Comma", sf::Keyboard::Comma},
        {"Period", sf::Keyboard::Period},
        {"Quote", sf::Keyboard::Quote},
        {"Slash", sf::Keyboard::Slash},
        {"BackSlash", sf::Keyboard::BackSlash},
        {"Tilde", sf::Keyboard::Tilde},
        {"Equal", sf::Keyboard::Equal},
        {"Dash", sf::Keyboard::Dash},
        {"Space", sf::Keyboard::Space},
        {"Return", sf::Keyboard::Return},
        {"BackSpace", sf::Keyboard::BackSpace},
        {"Tab", sf::Keyboard::Tab},
        {"PageUp", sf::Keyboard::PageUp},
        {"PageDown", sf::Keyboard::PageDown},
        {"End", sf::Keyboard::End},
        {"Home", sf::Keyboard::Home},
        {"Insert", sf::Keyboard::Insert},
        {"Delete", sf::Keyboard::Delete},
        {"Add", sf::Keyboard::Add},
        {"Subtract", sf::Keyboard::Subtract},
        {"Multiply", sf::Keyboard::Multiply},
        {"Divide", sf::Keyboard::Divide},
        {"Left", sf::Keyboard::Left},
        {"Right", sf::Keyboard::Right},
        {"Up", sf::Keyboard::Up},
        {"Down", sf::Keyboard::Down},
        {"Numpad0", sf::Keyboard::Numpad0},
        {"Numpad1", sf::Keyboard::Numpad1},
        {"Numpad2", sf::Keyboard::Numpad2},
        {"Numpad3", sf::Keyboard::Numpad3},
        {"Numpad4", sf::Keyboard::Numpad4},
        {"Numpad5", sf::Keyboard::Numpad5},
        {"Numpad6", sf::Keyboard::Numpad6},
        {"Numpad7", sf::Keyboard::Numpad7},
        {"Numpad8", sf::Keyboard::Numpad8},
        {"Numpad9", sf::Keyboard::Numpad9},
        {"F1", sf::Keyboard::F1},
        {"F2", sf::Keyboard::F2},
        {"F3", sf::Keyboard::F3},
        {"F4", sf::Keyboard::F4},
        {"F5", sf::Keyboard::F5},
        {"F6", sf::Keyboard::F6},
        {"F7", sf::Keyboard::F7},
        {"F8", sf::Keyboard::F8},
        {"F9", sf::Keyboard::F9},
        {"F10", sf::Keyboard::F10},
        {"F11", sf::Keyboard::F11},
        {"F12", sf::Keyboard::F12},
        {"F13", sf::Keyboard::F13},
        {"F14", sf::Keyboard::F14},
        {"F15", sf::Keyboard::F15},
        {"Pause", sf::Keyboard::Pause},
    };

    auto it = keyMap.find(keyString);
    if (it != keyMap.end())
        return it->second;
    return sf::Keyboard::Unknown;
}

ComponentFactory::ComponentFactory() {
    this->_components.emplace("position", [this](std::string id, const json& data) {
        int x = data["x"];
        int y = data["y"];
        return std::make_shared<PositionComponent>(id, x, y);
    });

    this->_components.emplace("sprite", [this](std::string id, const json& data) {
        std::string path = data["path"];
        int sizeTileX = data["sizeTileX"];
        int sizeTileY = data["sizeTileY"];
        int tileX = data["tileX"];
        int tileY = data["tileY"];
        return std::make_shared<SpriteComponent>(id, path, sizeTileX, sizeTileY, tileX, tileY);
    });

    this->_components.emplace("velocity", [this](std::string id, const json& data) {
        int x = data["x"];
        int y = data["y"];
        return std::make_shared<VelocityComponent>(id, x, y);
    });

    this->_components.emplace("movable", [this](std::string id, const json& data) {
    std::map<sf::Keyboard::Key, std::pair<int, int>> keybinds;
    for (const auto& entry : data["keybinds"].items()) {
        sf::Keyboard::Key key = mapStringToKeyboardKey(entry.key());
        int valueX = entry.value()["x"];
        int valueY = entry.value()["y"];
        keybinds[key] = std::make_pair(valueX, valueY);
    }
    return std::make_shared<MovableComponent>(id, keybinds);
});


    this->_components.emplace("size", [this](std::string id, const json& data) {
        int width = data["width"];
        int height = data["height"];
        return std::make_shared<SizeComponent>(id, width, height);
    });
}

std::shared_ptr<Component> ComponentFactory::getComponent(std::string name, std::string id, const json &data) {
    auto it = this->_components.find(name);

    if (it != this->_components.end())
        return it->second(id, data);

    return nullptr;
}