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
		void draw(Triangle triangle); 
		void draw(Triangle* triangle); 
		void draw(Triangle* triangle, Camera* camera);

		void draw(Planet* planet);

	private:
		Gpu* gpu;
		forward_list<int>* currentIteratorMap; 
		forward_list<int>* nextIteratorMap; 
		bool needDraw(Triangle* triangle);
};
#endif

