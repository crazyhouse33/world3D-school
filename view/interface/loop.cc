#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "camera.h"
#include "inputHandler.cc"

void error_callback(int error, const char* description)
	{
		fprintf(stderr, "Error: %s\n", description);
	}


//hello word programm took on glfw site

Camera* Camera::camera;//defining static variable (strange c++ behaviour)

//TODO for now main contain view shit until we succed to have a functionnal camera, then we gotta clean up and just initialise constantes and primordial things (camera, drawer...) 
int main(void)
{	
	int height=480;
	int width=640;
	float moveSpeed=1.0f;
	float rotationSpeed=0.0005f;
	float ratio = (float) width/height;
	float* initialPosition= (float*) malloc(3*sizeof(float));
	initialPosition[0]=0.0f;
	initialPosition[1]=0.0f;
	initialPosition[2]=1.0f;
	Camera::camera=new Camera(ratio, initialPosition, initialPosition, moveSpeed, rotationSpeed);

	//setting up conf, we dont want to use deprecated stuff	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//setting error callBack ( obviously before doing anything else)
	
	

	glfwSetErrorCallback(error_callback);

	//beginning use
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
	//linking window whit our callbacks
	glfwSetKeyCallback(window, key_callback);


	//locking cursor (fps mode) 
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



	//focus on this window
	glfwMakeContextCurrent(window);
	//setting cursor to 0,0 (need to be after focusing window)
	glfwSetCursorPos(window,0.0, 0.0);

	while (!glfwWindowShouldClose(window))
	{
		//update block (to put in Mover class (move all object that havent 0 as acceleration and check collision) 
		Camera::camera->move();
		//
		
	
		//render block(to put in renderer class
		Camera::camera->getViewMatrix(mouseToDirection(Camera::camera, window));	

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef((float) glfwGetTime() * 50.f, 0.f, 1.f, 1.f);
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();
		//essential stuff, SwapBuffer replace the ancient drawing whit the new, PollEvent process all event received since last poll event and proced them
		//TODO we should try to turn this busy wait into a lazy one see http://www.glfw.org/docs/latest/input_guide.html glfwWaitEvent()
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

//camera: prjojection matrix=attribute of camera, ModelMatrix = where it is and where its pointing at:
