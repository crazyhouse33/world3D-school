/**
 * Since glfw is written in c, this class had been created to emulate c++ callbacks (trying to respect POO) 
 * */
#ifndef INPUTMANAGER
#define INPUTMANAGER
#include "camera.h"
#include "interface.h"
#include <glm/glm.hpp> //vec3

class Interface; //forward declaration

class InputManager{
	public:
		InputManager(Interface* interface, Camera* camera);
		void upPress();
		void upRelease();
		void downPress();
		void downRelease();
		void leftPress();
		void leftRelease();
		void rightPress();
		void rightRelease();

		void escapePressed();

		glm::vec3 mouseToDirection();

	private:	
		Camera* camera;
		Interface* interface;
};
#endif
