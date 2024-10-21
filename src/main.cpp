#include <iostream>
#include <vector>
#include <stdexcept> // For std::runtime_error
extern "C" {
    #include <glad/glad.h>
}
#include <GLFW/glfw3.h>
#include <memory>

#include "shaderClass.h"
#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "Square.h"
#include "utils.h"
#include "Drawable.h"
#include "Line.h"

static GLfloat scale = 0.1f;
static GLfloat incr = 0.10f;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
    GLFWwindow* window = nullptr;

    try {
        // Initialize GLFW
        if (!glfwInit()) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(800, 800, "2D engine", NULL, NULL);
        if (!window) {
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glViewport(0, 0, 800, 800);
        glfwSetKeyCallback(window, keyCallback);

        Shader shader1("default.vert", "default.frag"); // Check for exceptions in Shader class
        std::vector<std::shared_ptr<Drawable>> draws;
	
        for (GLfloat x = -300.f; x < 300.f; x += 10.f)
        {
            float tempX = x/400.f;
            
            float tempY = tempX*tempX + 2*tempX - 10/400.f;
            draws.push_back(std::make_shared<Square>(tempX, tempY, 30));

        }
        GLuint uniID = glGetUniformLocation(shader1.ID, "sCale");

        while (!glfwWindowShouldClose(window)) {
            glClearColor(0.03f, 0.10f, 0.12f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            shader1.Activate();

            // Draw your objects here
            for(const auto& draw : draws)
            {
                draw->draw();
            }

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Clean up and terminate GLFW
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE) {
        scale += incr;
        incr += 0.1f;
        std::cout << "Space pressed. scale is -> " << scale << "\n";
    }
}
