//http://www.glfw.org/docs/latest/input_guide.html
//TODO put it in a class? dont move if acceleration=0


void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action ==GLFW_REPEAT){
		return;
	}
	switch(key){
		case GLFW_KEY_LEFT: 
			if (action==GLFW_PRESS){
				Camera::camera->accelerateLeft();
			}
			else{
				Camera::camera->accelerateRight();
			}
			break;

		case GLFW_KEY_UP:
			if (action==GLFW_PRESS){

				Camera::camera->accelerateForward();
			}
			else{
				Camera::camera->accelerateBackward();
			}
			break;

		case GLFW_KEY_RIGHT:
			if (action==GLFW_PRESS){

				Camera::camera->accelerateRight();
			}
			else{
				Camera::camera->accelerateLeft();

			}
			break;

		case GLFW_KEY_DOWN:
			if (action==GLFW_PRESS){
				Camera::camera->accelerateBackward();
			}
			else{
				Camera::camera->accelerateForward();
			}
			break;

		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);		
			break;

	}

}

