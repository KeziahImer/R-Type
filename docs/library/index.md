# Getting Started

The library is a piece of code used in the client to create R-Type.

> For now the library is directly installed on R-Type later on it would be able to install it on your own C++ source code trough CMake FetchContent.

## Build from source

### Requirements

The client use our library which itself use [SFML](https://www.sfml-dev.org/). SFML is automatically installed with our library. But some of SFML dependencies are needed on your machine to be able to build the client. Here the list of them:

- pthread
- opengl
- xlib
- udev
- xrandr
- xcursor
- freetype
- openal
- flac
- vorbis

### Build

To build a script is avaible on the scripts folder. Simply run the following command:

```sh
./scripts/genunix.sh
```

### Run client

The bin files can be found in the `out/bin` folder so simply run:

```sh
./out/bin/r-type_client
```
