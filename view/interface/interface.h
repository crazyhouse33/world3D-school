#ifndef INTERFACE
#define INTERFACE
#include <GLFW/glfw3.h>
#include "inputmanager.h"
class InputManager; //forward declaration
class Interface{
	public:	
		static InputManager* inputManager;//lib-unrelated callback wrapper 
		Interface(int width, int height);
		void getMousePosition(double* receiveX, double* receiveY);
		float getRatio();
		void closeWindow();
		bool windowShouldClose();
		void refreshBuffer();
		void threatEvents();
		void quit();
	private:
		GLFWwindow* window;	
		float ratio;
};
#endif
