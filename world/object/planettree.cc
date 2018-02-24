#include "planettree.h"
#include <stdlib.h>//malloc 
#include <math.h>//pow
#include<forward_list> //build recursion
#include <stdio.h>//TODO remove


float dist(float* p1, float* p2){
	float p1c=p1[0]-p2[0];
	float p2c=p1[1]-p2[1];
	float p3c=p1[2]-p2[2];
 return sqrt(p1c*p1c +p2c*p2c +p3c*p3c);
}

PlanetTree::PlanetTree(int depth, float radius, int sphericalAspect, int uniformity, int variationStrenght ){//TODO add 9(max) planet float input
	int nbTriangle=(4* (pow(3,depth)+1));
	array= (Triangle*) malloc((nbTriangle+1)*sizeof(Triangle));//+1 because first triangle not used
	
	printf("%d\n", nbTriangle);

	//constructing roots triangles (tetraedra) 
	
	float* hightPoint= (float*) malloc( sizeof(float)*3);
	hightPoint[0]=0.0;
	hightPoint[1]=radius;
	hightPoint[2]= 0.0;

	//need to know radius of the sphere at radius/3	
	//TODO precalculate sqrt value and hardcode it
	float subRadius=sqrt(8.0/9.0)*radius;

	float xCompund=sqrt(0.75)*subRadius;

	float* frontBasePoint= (float*) malloc( sizeof(float)*3);
	frontBasePoint[0]=0.0;
	frontBasePoint[1]= -radius/3.0;
	frontBasePoint[2]= -subRadius;
	float* leftBasePoint= (float*) malloc( sizeof(float)*3);
	leftBasePoint[0]=-xCompund;
	leftBasePoint[1]= -radius/3.0;
	leftBasePoint[2]= subRadius/2.0;
	float* rightBasePoint= (float*) malloc( sizeof(float)*3);
	rightBasePoint[0]=xCompund;
	rightBasePoint[1]= -radius/3.0;
	rightBasePoint[2]= subRadius/2.0;

	//preparing the building recursion 
 
	array[1]=Triangle(hightPoint, leftBasePoint, rightBasePoint);
	array[2]=Triangle(hightPoint,frontBasePoint, leftBasePoint);
	array[3]=Triangle(hightPoint, frontBasePoint, rightBasePoint);
	array[4]=Triangle(leftBasePoint,frontBasePoint,rightBasePoint);
	printf("%f %f %f %f %f %f\n", dist(hightPoint, frontBasePoint), dist(frontBasePoint,leftBasePoint), dist(hightPoint,rightBasePoint), dist(leftBasePoint,rightBasePoint), dist(hightPoint,leftBasePoint), dist(frontBasePoint, rightBasePoint)); 
	printf("%f %f %f\n", hightPoint[0]+frontBasePoint[0]+leftBasePoint[0]+rightBasePoint[0], hightPoint[1]+frontBasePoint[1]+leftBasePoint[1]+rightBasePoint[1], hightPoint[2]+frontBasePoint[2]+leftBasePoint[2]+rightBasePoint[2]); 	


	int recLimit= 4*pow(3, depth-1)+1;// last triangle of second last stage of tree
	for (int iterator=1; iterator< recLimit; iterator++){
		Triangle* current = getTriangle(iterator);
		float* crackPoint= current->crack(radius);

		array[getFirstSonIndex(iterator)]= Triangle(current->v1, current->v2,crackPoint);
		array[getSecondSonIndex(iterator)]= Triangle(current->v1, current->v3,crackPoint);	
		array[getThirdSonIndex(iterator)]= Triangle(current->v2, current->v3,crackPoint);
	}	
	



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


