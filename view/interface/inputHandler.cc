//http://www.glfw.org/docs/latest/input_guide.html
//TODO ranger ça quelque part
extern Camera* camera;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action ==GLFW_REPEAT){
		return;
	}
	switch(key){
		case GLFW_KEY_LEFT: 
			if (action==GLFW_PRESS){
				camera->accelerateLeft();
			}
			else{
				camera->accelerateRight();
			}
			break;

		case GLFW_KEY_UP:
			if (action==GLFW_PRESS){

				camera->accelerateForward();
			}
			else{
				camera->accelerateBackward();
			}
			break;

		case GLFW_KEY_RIGHT:
			if (action==GLFW_PRESS){

				camera->accelerateRight();
			}
			else{
				camera->accelerateLeft();

			}
			break;

		case GLFW_KEY_DOWN:
			if (action==GLFW_PRESS){
				camera->accelerateBackward();
			}
			else{
				camera->accelerateForward();
			}
			break;

		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);		
			break;

	}
}




