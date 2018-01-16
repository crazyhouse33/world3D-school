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


//TODO include le minimum nécéssaire
class Camera{
	private:
		double* position;
		double cursorX;
		double cursorY;
		bool dirty;
		glm::mat4 cachedViewMatrix;//to not recalcule the matrix if we did'not move
		glm::mat4 Projection;//settings of our camera
		//reste à gérer le model. rien compris à ça, j pense pas que ce soit important
	public: 
		Camera(double* position);
		void move(double* delta);//translating the camera by dx dy dz
		void rotate(double angle, double* axis); //axis is a vector, angle is in degree
		glm::mat4 getViewMatrix(bool actualize);//return the matrix for openGl
	};
#endif
