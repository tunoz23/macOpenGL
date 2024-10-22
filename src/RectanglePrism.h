
#pragma once

#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "Drawable.h"

class RectanglePrism : public Drawable
{
	
public:
	static GLuint shaderID;
	VertexArrayObject vao;
	std::optional<VertexBufferObject> vbo;
	std::optional<IndexBufferObject> ebo;

	GLfloat centerPosX;
	GLfloat centerPosY;
    GLfloat centerPosZ;
	GLfloat width, height, depth;

	std::vector<GLfloat> vertices;
	std::vector<GLuint>   indices;
public:
	RectanglePrism(const GLfloat _centerPosX, const GLfloat _centerPosY, const GLfloat _centerPosZ, GLfloat _width, GLfloat _height, GLfloat _depth);
	//Square(const GLuint _centerPosX, const GLuint _centerPosY, int width);
	void draw() override;
};

