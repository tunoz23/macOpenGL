#include <iostream>
#include <vector>
#include <stdexcept> // For std::runtime_error
extern "C" {
    #include <glad/glad.h>
}
#include <GLFW/glfw3.h>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderClass.h"
#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "Square.h"
#include "utils.h"
#include "Drawable.h"
#include "Line.h"
#include "RectanglePrism.h"


static GLfloat scale = 0.0f;
static GLfloat incr = 0.15f;

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
        draws.push_back(std::make_shared<RectanglePrism>(0.0f,0.0f,0.0f,0.3f,0.3f,0.3f));
       // draws.push_back(std::make_shared<Square>(0.0f,0.0f,0.3f));
        GLuint uniID = glGetUniformLocation(shader1.ID, "transform");
        
        
        glEnable(GL_DEPTH_TEST);
        while (!glfwWindowShouldClose(window)) {
            Timer timer;
            glClearColor(0.03f, 0.10f, 0.12f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            shader1.Activate();
            glm::mat4 resultMat = glm::mat4(1.f);    
            glm::mat4 persMat = glm::mat4(1.f);
            resultMat = glm::rotate(resultMat, scale, glm::vec3(1.0f,1.0f,1.0f));
            
          

            // Draw your objects here
            glUniformMatrix4fv(uniID,1,GL_FALSE,glm::value_ptr(resultMat));
         
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
        std::cout << "Space pressed. scale is -> " << scale << "\n";
    }
    
}
