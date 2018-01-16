#ifndef CAMERA
#define CAMERA

/*
 *
 * This class emulate a camera at coordonate xyz in the world, looking at direction x y z. 
 * It return the matrixs OPENGL need to render a buffer.
 * It's conceptually strange to threat the orientation whit the coordonates of the cursor 
 * (it intricate 2 differents concept), but it allow to just calculate 
 * the angle once, when we truly need redraw (for futur lazy wait aprroach ) 
 * */

#include <glm/glm.hpp>
using namespace glm;

//TODO include le minimum nécéssaire
class Camera{
	private:
		vec3 position;
		vec3 direction;	
		mat4 cachedViewMatrix;//to not recalcule the matrix if we did'not move
		mat4 projection;//settings of our camera
		//reste à gérer le model. rien compris à ça, j pense pas que ce soit important
	public: 
		Camera(float ratio, float* position, float* direction);
		void move(float* delta);//translating the camera by dx dy dz
		mat4 getViewMatrix(float* direction);//return the matrix for openGl, and save new direction
	};
#endif
