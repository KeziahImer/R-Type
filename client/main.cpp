
#include "rngine/SparseArray.hpp"
#include <iostream>

int main() {
  RNGine::SparseArray<int> arr;
  arr.insert_at(0, 1);
  arr.insert_at(56, 43);

  for (auto num : arr) {
    if (num.has_value()) {
      std::cout << *num << std::endl;
    }
  }
  return 0;
}
