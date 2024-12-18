# 2D Slasher Game Engine

This project is a 2D slasher game engine, inspired by games like Dead Cells. It is built using C++ and is designed to be used with the Visual Studio Code IDE.

## Building and Running the Project

To build and run the project, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/githubnext/workspace-blank.git
   ```
2. Navigate to the project directory:
   ```
   cd workspace-blank
   ```
3. Create a build directory and navigate to it:
   ```
   mkdir build && cd build
   ```
4. Run CMake to generate the build files:
   ```
   cmake ..
   ```
5. Build the project using Make:
   ```
   make
   ```
6. Run the executable:
   ```
   ./2DSlasherGame
   ```

## Dependencies

The project requires the following dependencies:

- CMake (version 3.10 or higher)
- A C++ compiler (GCC, Clang, or MSVC)
- SDL2 (Simple DirectMedia Layer) library
- SDL2_image library
- SDL2_mixer library
- SDL2_ttf library
