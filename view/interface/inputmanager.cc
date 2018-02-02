//http://www.glfw.org/docs/latest/input_guide.html
#include "inputmanager.h"
#include "debug.h"
#define GLM_FORCE_RADIANS
#include <glm/gtx/rotate_vector.hpp>//transforming mouse input into angle 

//to remove 

InputManager::InputManager(Interface* interface, Camera* camera){
	dirty=true;
	oldMouseX= 0.0;
	oldMouseY=0.0;

	left=false;
	right=false;
	up=false;
	down=false;
	this->camera=camera;
	this->interface=interface;
}
void InputManager::upPress(){
	up=true;
	down=false;
}

void InputManager::upRelease(){
	up=false;
}

void InputManager::downPress(){
	down=true;
	up=false;
}

void InputManager::downRelease(){
	down=false;
}

void InputManager::leftPress(){
	left=true;
	right=false;
}

void InputManager::leftRelease(){
	left=false;
}

void InputManager::rightPress(){
	right=true;
	left=false;
}

void InputManager::rightRelease(){
	right=false;
}

void InputManager::updateOrientation(){	
	//update direction
	double xMouseD, yMouseD;
	interface->getMousePosition(&xMouseD, &yMouseD);	
	float xMouse= (float) xMouseD;
	float yMouse=(float) yMouseD;
	if (xMouse == oldMouseX && yMouse == oldMouseY){// orientation did not change, dont rotate
		return;
	}
	if (xMouse!=oldMouseX){
		dirty=true;
	}
	oldMouseX=xMouse;
	oldMouseY=yMouse;
	float speed = camera->getRotationSpeed(); 
	vec3 initialDir=vec3(0.0f,0.0f,-1.0f);//TODO put up and right global, use more pointer, initial dir should be linked to the direction entered in the main
	vec3 up= vec3(0.0f,1.0f,0.0f);
	vec3 right =vec3(1.0f,0.0f,0.0f);
	initialDir=rotate(initialDir, -xMouse*speed, up);//- because anti clock rotation 
	initialDir=rotate(initialDir, yMouse*speed, right);
	camera->orient(initialDir);

#ifdef DEBUG
	printf("\nMouse Postion info: \n\nX= %f\nY=%f\nSpeed: %f \n",xMouse,yMouse,speed );
#endif
}
void InputManager::updateAcceleration(){	
	camera->stop();
	if (dirty==true){
		camera->resetCrossProduct();
		dirty=false;
	}
	if (up){
		camera->accelerateForward();
	}

	else if (down){
		camera->accelerateBackward();
	}

	if (left){
	 	camera->accelerateLeft();
	}
	else if(right){
		camera->accelerateRight();
	}
}

void InputManager::escapePressed(){
	interface->closeWindow();
}

void InputManager::update(){
	updateOrientation();
	updateAcceleration();
}
	

