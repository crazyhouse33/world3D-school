#ifndef GPU 
#define GPU

// Include Windows

#ifdef WIN32
#include <GL/glew.h>


// Include Mac

#elif __APPLE__
#define GL3_PROTOTYPES 1
#include <OpenGL/gl3.h>


// Include UNIX/Linux

#else
#define GL3_PROTOTYPES 1
#include <GLES3/gl3.h>

#endif//TODO METTRE ÇA dans un include crossplatform opengl

#include <glm/glm.hpp> //vec3
/*
 * This class do the link from world to view: it define how the data
 * should be rendered 
 * */
class Gpu{	
	public:
		
		//draw(ChainedTriangle* mesh)
		//draw(Triangle* triangle);
		void transferLookAtMatrix(mat4 lookAt);
		void transferProjection(mat4 projection);
	private:
		Gluint lookAtMatrixLocation;
		Gluint projectionMatrixLocation;	
};
#endif

