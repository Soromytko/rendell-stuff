# What is Rendell-Stuff?
Rendell-Stuff is a meta repository for building and versioning rendell libraries.

# How to use it?

Clone this repository using the ```--recursive``` flag.

```
git clone --recursive https://github.com/Soromytko/rendell-stuff.git
```

CMake is required for the build.

## Independent assembly 

The commands below will build the ```rendell_stuff``` static library:

```
mkdir build && cd build
cmake .. && cmake --build .
```

## Use in your project

Add the following code to your CMakeLists file:
```
set(RENDELL_UI_FONT_ROOT_DIRECTORY ${CMAKE_SOURCE_DIR}/res/Fonts/)
add_subdirectory(rendell-stuff)
target_link_libraries(${EXE_NAME} PUBLIC rendell_stuff)
```

The variable ```RENDELL_UI_FONT_ROOT_DIRECTORY``` contains the path to the resources used by the [Rendell-UI](https://github.com/Soromytko/).
