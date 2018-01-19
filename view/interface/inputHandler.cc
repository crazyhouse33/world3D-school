//http://www.glfw.org/docs/latest/input_guide.html
//TODO put it in a class? dont move if acceleration=0
#define GLM_FORCE_RADIANS
#include <glm/gtx/rotate_vector.hpp> 
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

vec3 mouseToDirection(Camera* camera, GLFWwindow* window){//TODO sauvegarder la matrice de rotation up et right et appliquer la multiplication	
	double xMouseD, yMouseD;
	glfwGetCursorPos(window, &xMouseD, &yMouseD);	
	float xMouse = (float) xMouseD;
	float yMouse = (float) yMouseD;
	float speed = Camera::camera->getRotationSpeed(); 
	vec3 initialDir=vec3(0.0f,0.0f,1.0f);
	vec3 up= vec3(0.0f,1.0f,0.0f);
	vec3 right =vec3(1.0f,0.0f,0.0f);
	initialDir=rotate(initialDir, xMouse*speed, up); 
	initialDir=rotate(initialDir, yMouse*speed, right);
	return initialDir;

}


