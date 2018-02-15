#include "gpu.h"

using namespace glm;
Gpu::Gpu(int maxRanderedTriangles){	
	//TODO quand plusieurs shaders, avoir une classe shader manager plutot
	//lo camera Shader 
	
	shader=new Shader("view/drawer/gpu/Shaders/geometry.vert", "view/drawer/gpu/Shaders/texture.frag");
	shader->charger(); //compiler le chargeur et le mettre sur la carte

	//recuperation of the matrixs adress
	lookAtMatrixLocation = glGetUniformLocation(shader->getProgramID(), "lookAtMatrix");
	projectionMatrixLocation = glGetUniformLocation(shader->getProgramID(), "projectionMatrix");
	if (projectionMatrixLocation==-1 || lookAtMatrixLocation==-1){
		printf("error while loading uniform address");
		exit(1);
	}

//Activate default mode (camera+depht test)

	cameraMode();
	glEnable(GL_DEPTH_TEST);



	//Manage VBO
	//get Id for the vbo
	glGenBuffers(1, &vboId);
	//locking new empty vbo
	glBindBuffer(GL_ARRAY_BUFFER, vboId);

	int neededSize= maxRanderedTriangles * 3 * sizeof(float);
	//allocating empty vram
	glBufferData(GL_ARRAY_BUFFER, neededSize, 0, GL_STREAM_DRAW);

}

Gpu::~Gpu(){
	glDeleteBuffers(1,&vboId);
	delete(shader);

}

void Gpu::transferProjectionMatrix(mat4 matrix){
	glUniformMatrix4fv(projectionMatrixLocation , 1, GL_FALSE, glm::value_ptr(matrix));
}

void Gpu::transferLookAtMatrix(mat4 matrix){
	glUniformMatrix4fv(lookAtMatrixLocation , 1, GL_FALSE, glm::value_ptr(matrix));
}

void Gpu::cameraMode(){
	glUseProgram(shader->getProgramID());
}

void Gpu::render(int n){//VBO shit

}
