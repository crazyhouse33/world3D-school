#include "gpu.h"
Gpu::Gpu(){
lookAtMatrixLocation = glGetUniformLocation(shader.getProgramID(), "lookAtMatrix");
projectionMatrixLocation = glGetUniformLocation(shader.getProgramID(), "projectionMatrix"); 
}

void Gpu::transferLookAtMatrix(mat4 matrix){
	glUniformMatrix4fv(lookAtMatrixLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Gpu::transferProjection(mat4 matrix){
	glUniformMatrix4fv(projectionMatrixLocation , 1, GL_FALSE, glm::value_ptr(matrix));
}
