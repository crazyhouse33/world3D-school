
#include <stdlib.h>
#include <stdio.h>


#include "interface.h"//need to be first (include glew)
#include "gpu.h" 
#include "camera.h"
#include "inputmanager.h"
#include "triangle.h"
#include "drawer.h"

//to move
#define GLM_FORCE_RADIANS
#include <glm/gtc/type_ptr.hpp> //cross plateform cast matrix to gpu


int main(void)
{	
	//initialisation des objets
	int height=480;
	int width=640;
	float moveSpeed=0.05f;
	float rotationSpeed=0.0005f;	
	float* initialPosition= (float*) malloc(3*sizeof(float));
	initialPosition[0]=0.0f;
	initialPosition[1]=0.0f;
	initialPosition[2]=-1.0f;
	float fov=0.6f;
	float nearLimit=0.1f;
	float farLimit=10000.0f;

	Interface* interface= new Interface(width, height);	
	Camera* camera=new Camera(interface->getRatio(), initialPosition, moveSpeed, rotationSpeed, fov, nearLimit, farLimit);	

	//TODO le main a un drawer, et pas un gpu
	Gpu* gpu=new Gpu(3000);
	Interface::inputManager=new InputManager(interface, camera, gpu);	
	gpu->cameraMode();//activating camera mode (use camera shader) once for all (never udapted yet)
	//sending settings of camera to GPU once for all (never udapted yet)	
	gpu->transferProjectionMatrix(camera->getProjectionMatrix(interface->getRatio()));

	Drawer* drawer= new Drawer(gpu);


	//creation de data (expériences)
	/*float p1= (float*)malloc(sizeof(float)*3);
	float* p2= (float*)malloc(sizeof(float)*3);
	float* p3= (float*)malloc(sizeof(float)*3);*/
	float p1[]={-0.6,-0.4,0.f};
	float p2[]={0.6f,-0.4f,0.f};	
	float p3[]={0.f,0.6f,0.f};

	Triangle triangle= Triangle(p1,p2,p3);

	glViewport(0, 0, width, height);
	while (!interface->windowShouldClose())
	{

		//update block (move all moveable accordingly to acceleration) 
		
		camera->move();

		//compute users inputs
		Interface::inputManager->update();
	
		/*glBegin(GL_LINE_LOOP);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();*/

		drawer->draw(triangle);
		//TODO we should try to turn this busy wait into a lazy one see http://www.glfw.org/docs/latest/input_guide.html glfwWaitEvent()
		interface->refreshBuffer();
		interface->threatEvents();//store input for later computation


	}
	interface->quit();
	delete(interface);
	delete(camera);
	delete(gpu);
	exit(EXIT_SUCCESS);
}


