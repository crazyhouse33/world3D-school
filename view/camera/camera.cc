#include "camera.h"
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
	upSideDown=false;
}

void Camera::orient(vec3 dir){

	direction=dir;	
}

void Camera::move(){
	position+=acceleration;
}


void Camera::accelerateForward(){
	acceleration += moveSpeed * direction;

	debug();

}

void Camera::accelerateBackward(){
	acceleration -= moveSpeed * direction;

	debug();
}


void Camera::accelerateRight(){// may be bugged if looking at up, also normed? TODO remplacer tous les constructeur int en float	
	acceleration -= moveSpeed * crossProduct;

	debug();
}

void Camera::accelerateLeft(){//idem
	acceleration += moveSpeed * crossProduct;

	debug();
}

void Camera::stop(){
	acceleration[0]=0;
	acceleration[1]=0;
	acceleration[2]=0;
}


void Camera::setCrossProduct(vec3 crossProduct){
	this->crossProduct=crossProduct;
}

vec3 Camera::getCrossProduct(){
	return crossProduct;
}

float Camera::getRotationSpeed(){
	return rotationSpeed;
}

void Camera::setUpsideDown(bool boolean){
	upSideDown=boolean;
}

mat4 Camera::getLookAtMatrix(){
	if (upSideDown){
	return lookAt(position,position+direction,vec3(0,-1,0));
	}
	else{
	return lookAt(position,position+direction,vec3(0,1,0));
	}
}

mat4 Camera::getProjectionMatrix(float ratio){
	return perspective(fov,ratio,nearLimit,farLimit);
}
#ifdef DEBUG
void Camera::debug(){
	printf("\nposition : %f, %f, %f\nacceleration : %f, %f, %f\ndirection : %f, %f, %f\nCrossProduct: %f %f %f \nnorme direction : %f\n",\
			position[0],position[1],position[2],\
			acceleration[0], acceleration[1],acceleration[2],\
			direction[0],direction[1],direction[2],\
			crossProduct[0], crossProduct[1], crossProduct[2],\
			length(direction));
}
#endif


