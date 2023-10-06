#include "rngine/Entity.hpp"
#include "rngine/Registry.hpp"
#include "rngine/SparseArray.hpp"
#include "rngine/SystemBundle.hpp"
#include <iostream>

int main() {
  RNGine::Entity entity = 0;
  RNGine::SparseArray<int> arr;
  arr.insert_at(0, 1);
  arr.insert_at(56, 43);

  for (auto num : arr) {
    if (num.has_value()) {
      std::cout << *num << std::endl;
    }
  }

  RNGine::SystemBundle bundle;

  bundle.push_back(
      []() { std::cout << "0 Hello world from bundle" << std::endl; });
  bundle.push_back(
      []() { std::cout << "1 Hello world from bundle" << std::endl; });
  bundle.push_back(
      []() { std::cout << "2 Hello world from bundle" << std::endl; });
  bundle.push_back(
      []() { std::cout << "3 Hello world from bundle" << std::endl; });

  bundle.run();

  RNGine::Registry registry;

  registry.addBundle(bundle);

  registry.run();

  auto test = registry.createEntity("test");
  registry.addComponent(test, 42);

  auto components = registry.getComponents<int>();
  auto component = components[test];

  std::cout << (component.has_value() ? *component : -84) << std::endl;
  component = components[54375];

  std::cout << (component.has_value() ? *component : -84) << std::endl;

  return 0;
}
