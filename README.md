***NOTE: Not ready for usage***

# CuckyGameEngine
Game engine designed for 2D and 3D game development in C++17.

## What is the CuckyGameEngine?
CuckyGameEngine is a game engine that is designed for 2D and 3D game development, provided through multiple (not currently) backends.

## Backends and dependencies
GLFW (ON by default)
* GLFW (Interface with window manager, input, events, etc.)
* GLEW (OpenGL, for rendering)
* GLM (OpenGL Mathematics, for rendering)
* miniaudio (Audio interface)

## Compilation
CuckyGameEngine comes with a CMakeLists file that will allow you to compile to a library and install it.

If you want to enable or disable any backend, you just set CGE_COMPILE_... (where ... is the backend name in UPPER_SNAKE_CASE) to ON or OFF.

You can see which backends are enabled by default above.

## Samples
There are some samples in the sample folder that show how to use CuckyGameEngine and its capabilities. These include:
* Generic: Some general usage of CuckyGameEngine.
