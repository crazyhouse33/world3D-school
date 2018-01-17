//http://www.glfw.org/docs/latest/input_guide.html
//TODO put it in a class? dont move if acceleration=0
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


	if (action==GLFW_PRESS){ 
		switch(key){
			case GLFW_KEY_Q:
				Camera::camera->accelerateLeft();
				break;

			case GLFW_KEY_Z:
				Camera::camera->accelerateForward();
				break;

			case GLFW_KEY_D:
				Camera::camera->accelerateRight();

				break;

			case GLFW_KEY_S:
				Camera::camera->accelerateBackward();
				break;

			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, GL_TRUE);		
				break;

		}
	}
	else if(action==GLFW_RELEASE){
		Camera::camera->resetAcceleration();
	}
	/*if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
	  glfwSetWindowShouldClose(window, GL_TRUE);
	  }*/
}

