/**
 * This class is for performance issue. It allows representation of a tree, but it skip all the nodes pointers, economising memory and time (their is a lot of node)
 * 
 * **/

#ifndef CHAINEDTRIANGLE
#define CHAINEDTRIANGLE
#include "triangle.h"
class ChainedTriangle : public Triangle{
	private:
		Triangle son1;
		Triangle son2;
		Triangle son3;

	public:
		Triangle getSon1();
		Triangle getSon2();
		Triangle getSon3();
}
