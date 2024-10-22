#include "QTWindow.h"

namespace Quantum {

    // Constructor: initializes GLFW, creates the window, and sets up OpenGL context
    QTWindow::QTWindow(int width, int height, const char* title)
        : width(width), height(height), title(title) {

        // Initialize GLFW
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW!" << std::endl;
            return;
        }

        // Set OpenGL version to 3.3 (Core Profile)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create the window
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window!" << std::endl;
            glfwTerminate();
            return;
        }

        // Set the OpenGL context for the window
        glfwMakeContextCurrent(window);

        // Load GLAD to get OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD!" << std::endl;
            glfwTerminate();
            return;
        }

        // Set the viewport size
        glViewport(0, 0, width, height);
    }

    // Destructor: cleans up resources
    QTWindow::~QTWindow() {
        Destroy();
    }

    // Update method: handles window events
    void QTWindow::Update() {
        glfwPollEvents();  // Process window events like input, resize, etc.
    }

    // Render method: clears the screen with a specified color
    void QTWindow::Render(glm::vec4 color) {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen with the color
        glfwSwapBuffers(window);       // Swap front and back buffers
    }

    // Destroy method: cleans up the window and GLFW resources
    void QTWindow::Destroy() {
        if (window) {
            glfwDestroyWindow(window);  // Destroy the window
        }
        glfwTerminate();                // Terminate GLFW
    }

}
