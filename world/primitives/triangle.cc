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

	float norm = distance / sqrt( vertex[2] * vertex[2] + vertex[1] * vertex[1] + vertex[0] * vertex[0]);
	
	vertex[0]*=norm;
	vertex[1]*=norm;
	vertex[2]*=norm;
	
	return vertex;
}
