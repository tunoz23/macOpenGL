#version 330 core
#define M_PI 3.1415926535897932384626433832795

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 Color;

uniform mat4 transform;
void main()
{
	
	gl_Position = transform * vec4(aPos, 1.0);
	Color = aColor;
}