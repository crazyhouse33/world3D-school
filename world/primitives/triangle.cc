#include "triangle.h"
#include <stdlib.h>
#include <math.h>
Triangle::Triangle(float* vertex1, float* vertex2, float* vertex3){
	v1=vertex1;
	v2=vertex2;
	v3=vertex3;
}

float* Triangle::crack(float distance){
	float* vertex = (float*) malloc(3* sizeof(float));

	//getting midle point
	vertex[0]= (v3[0]+v2[0]+v1[0])/3;
	vertex[1]= (v3[1]+v2[1]+v1[1])/3;
	vertex[2]= (v3[2]+v2[2]+v1[2])/3;

	//getting cross Product
	
	float crossX= v1[1] * v2[2] - v1[2]*v2[1];
	float crossY= v1[2] * v2[0] - v1[0]*v2[2];
	float crossZ= v1[0] * v2[1] - v1[1]*v2[0];


	//norming it
	float norm = distance / sqrt( crossZ * crossZ + crossY * crossY + crossX * crossX);
	
	crossX*=norm;
	crossY*=norm;
	crossZ*=norm;
	
	vertex[2]+=crossZ;
	vertex[1]+=crossY;
	vertex[0]+=crossX;

	return vertex;
}
