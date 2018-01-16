#include <camera.h>
//TODO configuration file/class for all hard coded shit
Camera::Camera(double* position){
		this.position=position;
		cursorX=0.0;
		cursorY=0.0;
		dirty=false;
		cachedViewMatrix=glm::mat4();//this is identity matrix
		projection=glm::perspective(
				30,//FOV (zoom en degrée)
				ratio,//depending size of windows TODO gerer ça
				0.1,// near limit
				1000,0//far limit
				)
}

/*We do nothing but changing that until we really need to calculate matrix 
 * just before rendering (lazy wait aproach wont trigger rendering) */
void Camera::move(double* delta){
	position[0]+=delta[0];
	position[1]+=delta[1];
	position[2]+=delta[2];
	dirty=true;
}

void Camera::rotate(c){

}

glm::mat4 Camera::getViewMatrix(bool actualize){
	if (dirty){//recalculating the matrixView
		dirty=false;
	}
	return cachedViewMatrix;
}
	

	
