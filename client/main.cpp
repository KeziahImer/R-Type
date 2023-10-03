#include <iostream>

#include "GameEngine/ECS.hpp"

int main()
{
    GameEngine::SparseArray<std::string> arr;

    auto refA = arr.insert_at(5, "10");
    auto refB = arr.insert_at(6, "11");

    for (size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    std::cout << "refA: " << arr.get_index(refA) << std::endl;
    std::cout << "refB: " << arr.get_index(refB) << std::endl;
    return 0;
}