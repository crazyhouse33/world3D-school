#ifndef PLANET
#define PLANET
#include "planettree.h"
class Planet : public PlanetTree{//extending for pratical purpose ( way lighter syntax)
		
	public:


		Planet(int depth,float* center, float radius, float sphericalAspect, float uniformity, float variationStrenght ) : PlanetTree(depth, radius, sphericalAspect, uniformity, variationStrenght){
			this->center=center;
		}
		float* getCenter();
		void moveCenter(double* deltaXYZ);

	private:

		float* center; //(x, y, z)
};
#endif
