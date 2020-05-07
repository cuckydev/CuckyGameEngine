***NOTE: Not ready for usage***

# CuckyGameEngine
Game engine designed for 2D and 3D game development in C++17.

## What is the CuckyGameEngine?
CuckyGameEngine is a game engine that is designed for 2D and 3D game development, provided through multiple (not currently) backends.

## Backends and dependencies
GLFW
* GLFW (Interface with window manager, input, events, etc.)
* GLEW (OpenGL, for rendering)
* GLM (OpenGL Mathematics, for rendering)
* miniaudio (Audio interface)

## Compilation
Compilation should be simple.
* First, allow CuckyGameEngine to be included as a library like so: `#include <CGE/CuckyGameEngine.h>`
* Second, set what backends are to be compiled, you do this by setting a definition for the compiler named -DCGE_COMPILE_... (where ... is the backend name).
* Third, you have to include and link the dependencies for each selected backend. Please refer to the list above. 
* Compile CGE/CuckyGameEngine.cpp alongside the rest of the program.

This repo comes with a sample program that can be compiled using the CMake file
