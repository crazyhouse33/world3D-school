#include "planettree.h"

PlanetTree::PlanetTree(int depth, vec3 center, float radius, int sphericalAspect, int uniformity, int variationStrenght ){//TODO add 9(max) planet float input
	array=malloc(4*pow(3,depth)*sizeof(Triangle));
	this->center=center;
	//constructing roots triangles (tetraedra) 
	
	vec3* hightPoint=new vec3(0.0,radius,0.0);

	//need to know radius of the sphere at radius/2	
	//TODO precalculate sqrt value and hardcode it
	float subRadius=sqrt(0.75)*radius;

	vec3* frontBasePoint= new vec3(0.0,-radius/2,-subRadius);
	vec3* leftBasePoint = new vec3( -subRadius, -radius/2, subRadius/2);
	vec3* rightBasePoint = new vec3( subRadius, -radius/2, subRadius/2);

	array[1]=Triangle(hightPoint, leftBasePoint, rightBasePoint );
	array[2]=Triangle(hightPoint,frontBasePoint, leftBasePoint);
	//may need reverte 
	array[3]=Triangle(hightPoint, frontBasePoint; rightBasePoint);

	array[4]=Triangle(leftBasePoint,frontBasePoint,rightBasePoint);
	

}

/*TODO inline it, try stange things (<< + n)*/
int PlanetTree::getFirstSonIndex(int i){
	return 3*i +2; 
}

int PlanetTree::getSecondSonIndex(int i){
	return 3*i +3;
}

int PlanetTree::getThirdSonIndex(int i){
	return 3*i +4;
}
