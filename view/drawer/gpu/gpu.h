#ifndef GPUGUARD
#define GPUGUARD

#include "Shader.h"
#include <glm/glm.hpp>

//to move in shader
#define GLM_FORCE_RADIANS
#include <glm/gtc/type_ptr.hpp> //cross plateform cast matrix to gpu

/*
 *
 * This class ensure gpu/cpu communication 
 *
 * */
class Gpu{
	public:
		Gpu(int maxRenderedTriangle);//compile camera shader, save Vram adress of constants, alloc bucket memory in both cpu/gpu side 
		~Gpu();	
		/*modify matrix in vram*/
		void transferLookAtMatrix(glm::mat4 matrix);
		void transferProjectionMatrix(glm::mat4 matrix);
		void cameraMode();//use camera Shaders
		void render(int n );//render n first triangles in VBO

	private:
		Shader* shader;
		GLuint lookAtMatrixLocation;//TODO pass it in the camera shader
		GLuint projectionMatrixLocation;//idem

		GLuint vboId;
		GLuint vboLocation;
		float* bucket;//mapped VBO memory, will be used as a bucket by cpu; 

};
#endif
