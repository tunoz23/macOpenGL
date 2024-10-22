#include "RectanglePrism.h"

RectanglePrism::RectanglePrism(const GLfloat _centerPosX, const GLfloat _centerPosY, const GLfloat _centerPosZ, GLfloat _width, GLfloat _height, GLfloat _depth)
    : centerPosX(_centerPosX), centerPosY(_centerPosY), centerPosZ(_centerPosZ), width(_width), height(_height), depth(_depth)
{
    // Vertices for a rectangular prism (front, back, left, right, top, and bottom faces)
    this->vertices =
    {
        // Front face
        centerPosX - width, centerPosY + height, centerPosZ + depth,  0.8f, 0.1f, 0.1f, // Top-left
        centerPosX + width, centerPosY + height, centerPosZ + depth,  0.1f, 0.8f, 0.1f, // Top-right
        centerPosX - width, centerPosY - height, centerPosZ + depth,  0.1f, 0.1f, 0.8f, // Bottom-left
        centerPosX + width, centerPosY - height, centerPosZ + depth,  0.9f, 0.9f, 0.1f, // Bottom-right

        // Back face
        centerPosX - width, centerPosY + height, centerPosZ - depth,  0.3f, 0.1f, 0.8f, // Top-left
        centerPosX + width, centerPosY + height, centerPosZ - depth,  0.5f, 0.3f, 0.7f, // Top-right
        centerPosX - width, centerPosY - height, centerPosZ - depth,  0.1f, 0.9f, 0.7f, // Bottom-left
        centerPosX + width, centerPosY - height, centerPosZ - depth,  0.7f, 0.2f, 0.4f, // Bottom-right
    };

    // Indices for drawing the rectangular prism with two triangles per face
    this->indices =
    {
        // Front face
        0, 1, 2,  // First triangle (top-left, top-right, bottom-left)
        1, 2, 3,  // Second triangle (top-right, bottom-left, bottom-right)

        // Back face
        4, 5, 6,  // First triangle (top-left, top-right, bottom-left)
        5, 6, 7,  // Second triangle (top-right, bottom-left, bottom-right)

        // Left face
        0, 4, 2,  // First triangle (front-top-left, back-top-left, front-bottom-left)
        4, 2, 6,  // Second triangle (back-top-left, front-bottom-left, back-bottom-left)

        // Right face
        1, 5, 3,  // First triangle (front-top-right, back-top-right, front-bottom-right)
        5, 3, 7,  // Second triangle (back-top-right, front-bottom-right, back-bottom-right)

        // Top face
        0, 1, 4,  // First triangle (front-top-left, front-top-right, back-top-left)
        1, 4, 5,  // Second triangle (front-top-right, back-top-left, back-top-right)

        // Bottom face
        2, 3, 6,  // First triangle (front-bottom-left, front-bottom-right, back-bottom-left)
        3, 6, 7   // Second triangle (front-bottom-right, back-bottom-left, back-bottom-right)
    };

    vao.bind();
	this->vbo = VertexBufferObject(this->vertices);
	this->ebo = IndexBufferObject(this->indices);
	vao.linkAttrib(vbo.value(), 0,3, GL_FLOAT,6*sizeof(GLfloat),(void*)0);
	vao.linkAttrib(vbo.value(), 1,3, GL_FLOAT,6*sizeof(GLfloat),(void*)(3 * sizeof(GLfloat)));
	vao.unBind();
	ebo.value().unBind();

}
void RectanglePrism::draw()
{
	vao.bind();
	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
	vao.unBind();
}

