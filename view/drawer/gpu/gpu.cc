#include "gpu.h"
using namespace glm;
Gpu::Gpu(){
//TODO quand plusieurs shaders, avoir une classe shader manager plutot
	//loading camera Shader 
	shader=new Shader("view/drawer/gpu/Shaders/geometry.vert", "view/drawer/gpu/Shaders/texture.frag");
	shader->charger(); //compiler le chargeur et le mettre sur la carte
	
	//recuperation of the matrixs adress
	lookAtMatrixLocation = glGetUniformLocation(shader->getProgramID(), "lookAtMatrix");
	projectionMatrixLocation = glGetUniformLocation(shader->getProgramID(), "projectionMatrix");
	if (projectionMatrixLocation==-1 || lookAtMatrixLocation==-1){
		printf("error while loading uniform address");
		exit(1);
	}

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
