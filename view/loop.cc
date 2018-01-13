#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

//hello word programm took on glfw site

//TODO separated file, we can add more callBacks (mouse, shouldclose....) http://www.glfw.org/docs/latest/input_guide.html
void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos){
	//modify orientation of the camera
	printf("x: %f, y%f\n",xpos , ypos);
}
void error_callback(int error, const char* description)
{
	    fprintf(stderr, "Error: %s\n", description);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

//TODO for now main contain view shit until we succed to have a functionnal camera, then we gotta clean up and just initialise constantes and primordial things (camera, drawer...) 
int main(void)
{
	
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
	GLFWwindow* window=glfwCreateWindow(640, 480, "3DWorld", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//linking window whit our callbacks
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);

	//locking cursor (fps mode)
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	//focus on this window
	glfwMakeContextCurrent(window);
	
	
	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
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
