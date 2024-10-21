#version 330 core
#define M_PI 3.1415926535897932384626433832795

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 Color;

uniform float sCale; 

void main()
{
	vec3 pos = vec3(aPos.x, aPos.y, 0.0);
	vec3 resultPos = mat3(
		cos(M_PI/2), -sin(M_PI/2),0.0,
		sin(M_PI/2), cos(M_PI/2),0.0,
		0.0, 		0.0,	1.0
	)
	*pos;
	gl_Position = vec4(pos, 1.0);
	Color = aColor;
}