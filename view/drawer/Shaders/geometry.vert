#version 330 core
layout (location = 0) in vec3 vertex; 
uniform mat4 cameraMatrix;

void main()
{
    gl_Position = cameraMatrix * vec4(vertex, 1.0f);
} 
