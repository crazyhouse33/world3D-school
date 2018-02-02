/**
 * Since glfw is written in c, this class had been created to emulate c++ callbacks (trying to respect POO)
 * It also contain all computation concerning users inputs for the camera.  
 * */
#ifndef INPUTMANAGER
#define INPUTMANAGER
#include "camera.h"
#include "interface.h"
#include "gpu.h"
#include <glm/glm.hpp> //vec3

class Interface; //forward declaration

class InputManager{
	public:
		InputManager(Interface* interface, Camera* camera, Gpu* gpu);
		//lazy callbacks
		void upPress();
		void upRelease();
		void downPress();
		void downRelease();
		void leftPress();
		void leftRelease();
		void rightPress();
		void rightRelease();
		void escapePressed();

		//update Camera according to inputs (contain all conputation)
		void update();

		/**
		 * orient camera and return view Matrix associated
		 * */
	private:	
		Camera* camera;
		Interface* interface;
		//needed to transfer view matrix to gpu 
		Gpu* gpu;
		bool right;
		bool left;
		bool up;
		bool down;
		/*return true if acceleration changed since last time*/
		bool updateAcceleration();
		bool updateOrientation();

		//cheap optim

		vec3 oldXrotation;
		float oldMouseX;
		float  oldMouseY;
		};
#endif
