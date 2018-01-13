#include "chainedTriangle.h"
ChainedTriangle::getSon1(){
	return son1;
}
ChainedTriangle::getSon2(){
	return son2;
}
ChainedTriangle::getSon3(){
	return son3;
}

ChainedTriangle::crack(double* vertex){
	Triangle** triangles=Triangle::crack(vertex);
	son1=triangles[0];
	son2=triangles[1];
	son3=triangles[2];
}
