#include <GLFW/glfw3.h>
#include "interface.h"
#include "inputhandler.cc"//key callback
#include <stdlib.h>//error control
#include <stdio.h>

/**
 * This class contain all thing related to glfw
 * */

void error_callback(int error, const char* description)
	{
		fprintf(stderr, "Error: %s\n", description);
	}


Interface::Interface(int width, int height){
	ratio=(float) width/height;
	//setting up conf, we dont want to use deprecated stuff	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//setting error callBack ( obviously before doing anything else)
	glfwSetErrorCallback(error_callback);

	if (!glfwInit()){
		exit(EXIT_FAILURE);
	}
	//creation of the window
	GLFWwindow* window=glfwCreateWindow(width, height, "3DWorld", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//linking window whit key callbacks
	glfwSetKeyCallback(window, key_callback);


	//locking cursor (fps mode) 
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



	//focus on this window
	glfwMakeContextCurrent(window);
	//setting cursor to 0,0 (need to be after focusing window)
	glfwSetCursorPos(window,0.0, 0.0);

}

void Interface::getMousePosition(double* receiveX, double* receiveY){
	glfwGetCursorPos(window, receiveX, receiveY);	


}

bool Interface::windowShouldClose(){
	return glfwWindowShouldClose(window); 
}

float Interface::getRatio(){
	return ratio;
}

void Interface::refreshBuffer(){
	glfwSwapBuffers(window);
}

void Interface::threatEvents(){
	glfwPollEvents();
}

void Interface::quit(){
glfwDestroyWindow(window);
glfwTerminate();
}
