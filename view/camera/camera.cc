#include <camera.h>

#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
//TODO configuration file/class for all hard coded things

Camera::Camera(float ratio, float* position, float* direction){
		this->position=vec3(position[0],position[1],position[2]);
	 	this->direction=vec3(direction[0],direction[1],direction[2]);
		cachedViewMatrix=glm::mat4();//this is identity matrix
		projection=perspective(
				30.0f,//FOV (zoom en degrée)
				ratio,//depending size of windows TODO gerer ça
				0.1f,// near limit
				10000.0f//far limit
				);
}

/*We do nothing but changing that until we really need to calculate matrix 
 * just before rendering (lazy wait aproach wont trigger rendering) */
void Camera::move(float* delta){
	position[0]+=delta[0];
	position[1]+=delta[1];
	position[2]+=delta[2];
}

mat4 Camera::getViewMatrix(float* dir){
	direction[0]=dir[0];
	direction[1]=dir[1];
	direction[2]=dir[2];
	lookAt( position, position+direction , vec3(0,1,0));
}
	

	
