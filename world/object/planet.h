#ifndef PLANET
#define PLANET
#include "planettree.h"
class Planet : PlanetTree{//extending for pratical purpose ( way lighter syntax)
		
	public:


		Planet(int depth,float* center, float radius, int sphericalAspect, int uniformity, int variationStrenght ) : PlanetTree(depth, radius, sphericalAspect, uniformity, variationStrenght){
			this->center=center;
		}
		float* getCenter();
		void moveCenter(double* deltaXYZ);

	private:

		float* center; //(x, y, z)
};
#endif
