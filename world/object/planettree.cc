#include "planettree.h"
#include <stdlib.h>//malloc 
#include <math.h>//pow
PlanetTree::PlanetTree(int depth, float radius, int sphericalAspect, int uniformity, int variationStrenght ){//TODO add 9(max) planet float input
	array= (Triangle*) malloc(4*pow(3,depth)*sizeof(Triangle));

	//constructing roots triangles (tetraedra) 
	
	float* hightPoint= (float*) malloc( sizeof(float)*3);
	hightPoint[0]=0.0;
	hightPoint[1]=radius;
	hightPoint[2]= 0.0;


	//need to know radius of the sphere at radius/2	
	//TODO precalculate sqrt value and hardcode it
	float subRadius=sqrt(0.75)*radius;

	float* frontBasePoint= (float*) malloc( sizeof(float)*3);
	frontBasePoint[0]=0.0;
	frontBasePoint[1]= -radius/2;
	frontBasePoint[2]= -subRadius/2;

	float* leftBasePoint= (float*) malloc( sizeof(float)*3);
	leftBasePoint[0]=-subRadius;
	leftBasePoint[1]= -radius/2;
	leftBasePoint[2]= subRadius/2;

	float* rightBasePoint= (float*) malloc( sizeof(float)*3);
	rightBasePoint[0]=subRadius;
	rightBasePoint[1]= -radius/2;
	rightBasePoint[2]= subRadius/2;

	array[1]=Triangle(hightPoint, leftBasePoint, rightBasePoint);
	array[2]=Triangle(hightPoint,frontBasePoint, leftBasePoint);
	//may need revert 
	array[3]=Triangle(hightPoint, frontBasePoint, rightBasePoint);

	array[4]=Triangle(leftBasePoint,frontBasePoint,rightBasePoint);
	

}

/*TODO inline it, try stange things (<< + n)* ++ an shit*/
int PlanetTree::getFirstSonIndex(int i){
	return 3*i +2; 
}

int PlanetTree::getSecondSonIndex(int i){
	return 3*i +3;
}

int PlanetTree::getThirdSonIndex(int i){
	return 3*i +4;
}

int PlanetTree::getLeft(int i){
	return i-1;
}

int PlanetTree::getRight(int i){
return i+1;
}
