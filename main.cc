
#include <stdlib.h>
#include <stdio.h>


#include "interface.h"//need to be first (include glew)
#include "gpu.h" 
#include "camera.h"
#include "inputmanager.h"
#include "triangle.h"
#include "drawer.h"
#include "planet.h"

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
	//sending settings of camera to GPU once for all (never udapted yet)	
	gpu->transferProjectionMatrix(camera->getProjectionMatrix(interface->getRatio()));

	Drawer* drawer= new Drawer(gpu);


	//creation de data
	float* center= (float*)malloc(sizeof(float)*3);
	center[0]=0.0;
	center[1]=0.0;
	center[2]=0.0;
	float radius=1;
	Planet* planet=new Planet(1, center, radius, 1.0,1.0,1.0);

	//TODO le foutre ailleur
	glViewport(0, 0, width, height);

	while (!interface->windowShouldClose())
	{

		//compute users inputs
		Interface::inputManager->update();


		//update world (move all moveable accordingly to acceleration) 
		camera->move();

				
		//draw
		drawer->draw(planet);
		//TODO we should try to turn this busy wait into a lazy one see http://www.glfw.org/docs/latest/input_guide.html glfwWaitEvent() ( or just sleep)
		interface->refreshBuffer();
		interface->threatEvents();//store input for later computation


	}
	interface->quit();
	delete(interface);
	delete(camera);
	delete(gpu);
	delete(drawer);
	exit(EXIT_SUCCESS);
}


