# R-type

R-type is a project that aims to reimagine the classic game "R-type" in C++ using a custom game engine and implementing networked multiplayer functionality.

## Development

### Windows

**Requirements**

- CMake 3.10+
- Mingw 8.0.0
- nsis 3.0

**Build**

```sh

```

**Docs**

```sh
mkdocs build && mkdocs serve
```

### Linux

**Requirements**

- CMake 3.10+
- Mkdocs 1.5.2

**Build**

```sh
mkdir -p build && cd build
cmake ..
make # use "-j N" for N parallel jobs
```

**Docs**

```sh
mkdocs build && mkdocs serve
```
