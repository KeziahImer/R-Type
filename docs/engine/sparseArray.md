# Class SparseArray

The `SparseArray` class is a data structure designed to store an array of optional data. It is used in the R-type game engine to efficiently manage components.

## Usage

The `SparseArray` class is a generic container designed to store data of type `Component`. It provides a set of methods to access, insert, remove, and search for elements in the array.

## Constructors

The `SparseArray` class has a default constructor, a copy constructor, a move constructor, and a destructor.

## Operators

- `operator[]`: Allows access to an element in the array by its index. If the index is greater than the current size of the array, an empty element of type `Component` is returned.

## Methods

- `begin`, `end`, `cbegin`, `cend`: Allow traversing the array using iterators.
- `size`: Returns the current size of the array.
- `insert_at`: Inserts a `Component` element at a given position in the array.
- `erase`: Removes an element at a given position in the array.
- `get_index`: Returns the index of an element in the array.

## Example Usage

```cpp
// Creating a SparseArray of components
RNGine::SparseArray<Component> sparseArray;

// Inserting a component at index 3
Component comp;
sparseArray.insert_at(3, comp);

// Accessing a component at index 1
Component retrievedComp = *sparseArray[1];

```