# QuantumForge

QuantumForge is an advanced OpenGL-based graphics engine built for modern game development and interactive 3D applications. It is designed to be highly modular, efficient, and developer-friendly, offering a complete suite of features for rendering, physics, sound, UI, and more.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Features

- **Real-time Rendering:** Supports high-performance real-time 3D rendering using OpenGL.
- **Physics Engine:** Integrated physics system for realistic object interaction.
- **Audio Engine:** 3D sound integration using OpenAL.
- **Entity-Component System:** Efficient entity management powered by EnTT.
- **UI System:** Built-in ImGui and custom widgets for creating interactive interfaces.
- **Custom Shader System:** Easily manage and create OpenGL shaders.
- **Model Loading:** Assimp support for loading a wide range of 3D model formats.
- **Scene Management:** Organize and render complex scenes efficiently.
- **Cross-Platform:** Supports Windows, Linux, and macOS.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following installed:

- C++17 or higher
- OpenGL 4.5 or higher
- CMake (version 3.16+)
- GLFW
- GLAD
- Assimp
- FreeType (for text rendering)
- OpenAL (for audio)
- ImGui and ImGuizmo

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/QuantumForge.git
    cd QuantumForge
    ```

2. Create a build directory and compile:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Run the application:
    ```bash
    ./QuantumForge
    ```

## Usage

Once the engine is compiled, you can start developing your 3D applications. The engine supports custom shaders, model loading, and scene management right out of the box.

### Example Code

Here's a simple example to load a 3D model and render it:

```cpp
#include <VEGA/VEGA/Window.h>
#include <VEGA/Rendering/Renderer.h>
#include <VEGA/Resources/Model.h>

int main() {
    vega::Window window(1280, 720, "QuantumForge Demo");
    vega::Renderer renderer;
    
    vega::Model model("path/to/your/model.obj");
    
    while (!window.shouldClose()) {
        window.processInput();
        renderer.render(model);
        window.swapBuffers();
    }
    
    return 0;
}
