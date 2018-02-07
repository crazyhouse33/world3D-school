#ifndef GPUGUARD
#define GPUGUARD

#include <GL/glew.h>

#include "Shader.h"
#include <glm/glm.hpp>

//to move in shader?
#define GLM_FORCE_RADIANS
#include <glm/gtc/type_ptr.hpp> //cross plateform cast matrix to gpu


class Gpu{
	public:
		Gpu();//compile camera shader, save Vram adress of constants, initialise Opengl Extensions
		/*modify matrix in vram*/
		void transferLookAtMatrix(glm::mat4 matrix);
		void transferProjectionMatrix(glm::mat4 matrix);

		void cameraMode();//use camera Shaders
	private:
		Shader* shader;
		GLuint lookAtMatrixLocation;//TODO pass it in the camera shader
		GLuint projectionMatrixLocation;//idem

};
#endif
