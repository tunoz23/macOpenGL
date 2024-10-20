#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept> // For std::runtime_error

// Function to read file contents
std::string get_file_contents(const char* filename);

class Shader {
public:
    // Reference ID of the Shader Program
    GLuint ID;

public:
    // Constructor that builds the Shader Program from 2 different shaders
    Shader(const char* vertexFile, const char* fragmentFile);

    // Activates the Shader Program
    void Activate();
    
    // Deletes the Shader Program
    void Delete();

private:
    void checkErrors(GLuint shaderId);
    void checkProgramErrors(); // Remove 'Shader::' prefix
};
