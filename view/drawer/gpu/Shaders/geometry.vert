#version 330 core
layout (location = 0) in vec3 vertex; 
uniform mat4 lookAtMatrix; 
uniform mat4 projectionMatrix;

void main()
{
    gl_Position = projectionMatrix * lookAtMatrix * vec4(vertex, 1.0f);
} 
