#ifndef PLANET
#define PLANET
#include "chainedTriangle.h"
#include <forward_list>
class Planet{
	private:
		ChainedTriangle** mesh; //the first level of precision
		
		/*basic data used for random generation*/
		int humidity;
		double temperatureAtEcuador;
		double* center; //(x, y, z)
		/*for now we use fixed temp at ecuador, if we got enought
		time we will generate smalls suns systems where temperature
		is more realisticlely regulated 
		Planet** suns;
		*/
	
	public:
		/*
		 * Function returning the actual temperature of the planet 
		 * on a given point
		 * */

		double temperatureAtVertex(double* Vertex);
		double*getCenter();
		void moveCenter(double* dxyz);
}
