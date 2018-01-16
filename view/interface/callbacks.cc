//http://www.glfw.org/docs/latest/input_guide.html

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

