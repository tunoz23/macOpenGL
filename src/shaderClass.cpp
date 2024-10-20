#include "shaderClass.h"
#include <stdexcept> // For std::runtime_error

#include "vertexData.h"
#include "fragData.h"
// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename) {
    std::ifstream in(filename, std::ios::binary);
    if (in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    throw std::runtime_error("Failed to read file: " + std::string(filename));
}

// Constructor that builds the Shader Program from 2 different shaders
Shader::Shader(const char* vertexFile, const char* fragmentFile) {
    // Read vertexFile and fragmentFile and store the strings
   // std::string vertexCode = get_file_contents(vertexFile);
   // std::string fragmentCode = get_file_contents(fragmentFile);

    // Convert the shader source strings into character arrays
	std::string vertexCode = std::string(vertexData);
	std::string fragCode = std::string(fragData);
    const GLchar* vertexSource = vertexCode.c_str();
    const GLchar* fragmentSource = fragCode.c_str();

    // Create Vertex Shader Object and get its reference
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach Vertex Shader source to the Vertex Shader Object
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    // Compile the Vertex Shader into machine code
    glCompileShader(vertexShader);
    
    // Check Vertex Shader compilation errors
    checkErrors(vertexShader);

    // Create Fragment Shader Object and get its reference
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Attach Fragment Shader source to the Fragment Shader Object
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    // Compile the Fragment Shader into machine code
    glCompileShader(fragmentShader);
    
    // Check Fragment Shader compilation errors
    checkErrors(fragmentShader);

    // Create Shader Program Object and get its reference
    ID = glCreateProgram();
    // Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    // Wrap-up/Link all the shaders together into the Shader Program
    glLinkProgram(ID);

    // Delete the now useless Vertex and Fragment Shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

// Activates the Shader Program
void Shader::Activate() {
    glUseProgram(ID);
}

// Deletes the Shader Program
void Shader::Delete() {
    glDeleteProgram(ID);
}

void Shader::checkErrors(GLuint shader) {
    GLint success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
        throw std::runtime_error("Shader compilation failed:\n" + std::string(infoLog));
    }
}

void Shader::checkProgramErrors() {
    GLint success;
    char infoLog[512];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(ID, sizeof(infoLog), NULL, infoLog);
        throw std::runtime_error("Shader program linking failed:\n" + std::string(infoLog));
    }
}
