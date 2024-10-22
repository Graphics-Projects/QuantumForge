#ifndef WINDOW_H
#define WINDOW_H

#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Quantum {
    class QTWindow {
    public:
        // Constructor
        QTWindow(int width, int height, const char* title);
        
        // Destructor
        ~QTWindow();

        // Window update method (handles events)
        void Update();

        // Rendering method with a color parameter
        void Render(glm::vec4 color);

        // Method to check if the window should close
        inline bool ShouldClose() const { return glfwWindowShouldClose(window); }

        // Cleanup resources
        void Destroy();

    private:
        GLFWwindow* window;  // Pointer to the GLFW window
        int width, height;   // Window dimensions
        const char* title;   // Window title
    };
}

#endif // WINDOW_H
