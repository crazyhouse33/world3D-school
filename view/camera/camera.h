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

//TODO mettre une méthode dirty, si non dirty pas besoin de remetre l'uniforme des matrice à jour (moins de calcul et moin de com C/Gpu)
class Camera{
	private:
		vec3 acceleration;
		vec3 position;
		vec3 direction;//normed vector direction	

				//cheap optim
		vec3 cachedCrossProduct;
		
		//settings 
		float fov;
		float nearLimit;
		float farLimit;
		float moveSpeed;
		float rotationSpeed;
	public: 
		Camera(float ratio, float* position, float moveSpeed, float rotationSpeed, float fov, float nearLimit, float farLimit);
		void accelerateLeft();
		void accelerateForward();
		void accelerateBackward();
		void accelerateRight();	
		void stop();
		void resetCrossProduct();
		float getRotationSpeed();
		void move();//translate camera accordingly to acceleration	
		void orient(vec3 direction);//orient camera

		mat4 getLookAtMatrix();
		mat4 getProjectionMatrix();


#ifdef DEBUG
		void debug();
#endif
		};


#endif
