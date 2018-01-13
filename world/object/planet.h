#ifndef PLANET
#define PLANET
#include "chainedTriangle.h"
class Planet{
	private:
		ChainedTriangle* mesh;
		/*basic data used for random generation*/
		int humidity;
		int temperatureAtEcuador
		/*for now we use fixed temp at ecuador, if we got enought
		time we will generate smalls suns systems where temperature
		is more realisticlely regulated 

		Planet** suns;
		*/
		/*
		 * Function returning the actual temperature of the planet 
		 * on a given point*/

	public:
		double temperatureAtVertex(double* Vertex);
}
