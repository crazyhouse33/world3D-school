#include "camera.h"
#include <stdio.h>
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include "debug.h"
//TODO configuration file/class for all hard coded things

Camera::Camera(float ratio, float* position, float moveSpeed, float rotationSpeed, float fov, float nearLimit, float farLimit){
	this->acceleration=vec3();
	this->position=vec3(position[0],position[1],position[2]);
	this->direction=vec3(direction[0],direction[1],direction[2]);
	this->moveSpeed=moveSpeed;
	this->rotationSpeed=rotationSpeed;
	this->fov=fov;
	this->nearLimit=nearLimit;
	this->farLimit=farLimit;
}

void Camera::orient(vec3 dir){
	direction=dir;
}

void Camera::move(){
	position+=acceleration;
	debug();
}


void Camera::accelerateForward(){
	acceleration += moveSpeed * direction;

}

void Camera::accelerateBackward(){
	acceleration -= moveSpeed * direction;
}


void Camera::accelerateRight(){// may be bugged if looking at up, also normed? TODO remplacer tous les constructeur int en float	
	acceleration -= moveSpeed * cachedCrossProduct;
}

void Camera::accelerateLeft(){//idem
	acceleration += moveSpeed * cachedCrossProduct;
}

void Camera::stop(){
	acceleration[0]=0;
	acceleration[1]=0;
	acceleration[2]=0;
}


void Camera::resetCrossProduct(){
	cachedCrossProduct= cross( vec3(0,1,0), direction);//TODO up global	
}

float Camera::getRotationSpeed(){
	return rotationSpeed;
}

mat4 Camera::getLookAtMatrix(){
	return lookAt(position,position+direction,vec3(0,1,0));
}

mat4 Camera::getProjectionMatrix(float ratio){
	return perspective(fov,ratio,nearLimit,farLimit);
}
#ifdef DEBUG
void Camera::debug(){
	printf("\nposition : %f, %f, %f\n\
			acceleration : %f, %f, %f\n\
			direction : %f, %f, %f\n\
			norme direction : %f\n",\
			position[0],position[1],position[2],\
			acceleration[0], acceleration[1],acceleration[2],\
			direction[0],direction[1],direction[2],\
			length(direction));
}
#endif


