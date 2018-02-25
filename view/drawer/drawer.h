#ifndef DRAWER 
#define DRAWER
#include "triangle.h"
#include "planet.h"
#include "gpu.h"
#include "camera.h"
#include <forward_list>
/*
 * This class do the link from world to view: it define how the data
 * should be rendered 
 * */
class Drawer{	
	public:
		Drawer(Gpu* gpu);
		void draw(Planet* planet, Camera* camera, float maxDistance);

	private:
		Gpu* gpu;
		void draw(Triangle* triangle); 

		bool Drawer::needDraw(Triangle* triangle,Camera* camera, float maxDistance);
		forward_list<int>* currentIteratorMap; 
		forward_list<int>* nextIteratorMap; 		
};
#endif

