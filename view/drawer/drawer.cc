#include "drawer.h"

Drawer::Drawer(Gpu* gpu){
	this->gpu=gpu;
}
void Drawer::draw(Triangle triangle){//TODO use VBO thanks to gpu class determine
	glBegin(GL_LINE_LOOP);
	glVertex3f(triangle.v1[0],triangle.v1[1], triangle.v1[2]);
	glVertex3f(triangle.v2[0],triangle.v2[1], triangle.v2[2]);
	glVertex3f(triangle.v3[0],triangle.v3[1], triangle.v3[2]);
	glEnd();
}

void Drawer::draw(Triangle* triangle){//TODO use VBO thanks to gpu class
	glBegin(GL_LINE_LOOP);
	glVertex3f(triangle->v1[0],triangle->v1[1], triangle->v1[2]);
	glVertex3f(triangle->v2[0],triangle->v2[1], triangle->v2[2]);
	glVertex3f(triangle->v3[0],triangle->v3[1], triangle->v3[2]);
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex3f(triangle->v1[0],triangle->v1[1], triangle->v1[2]);
	glVertex3f(triangle->v2[0],triangle->v2[1], triangle->v2[2]);
	glVertex3f(triangle->v3[0],triangle->v3[1], triangle->v3[2]);
	glEnd();

}

void Drawer::draw(Planet* planet){//TODO true recursion, CHANGE MODEL VIEW ACCORDING TO CENTER
	for (int i=5 ; i<17;i++){
		draw(planet->getTriangle(i));
	}
}


void Drawer::draw(Planet* planet, Camera* camera){//TODO true recursion, CHANGE MODEL VIEW ACCORDING TO CENTER
currentIteratorMap->push_front(1);
currentIteratorMap->push_front(4);
bool phase=true;
while (!currentIteratorMap->empty()){
	int from= currentIteratorMap->front();
	currentIteratorMap->pop_front();
	int to = currentIteratorMap->front();
	currentIteratorMap->pop_front();
	for (i=from ; i<=to ; i++){
		Triangle* current = planet->getTriangle(i);
		if (needDraw(triangle) != phase){
			nextIteratorMap->push_front(planet->getFirstSon(i));
			phase=!phase;
		}	
			

	}
}


bool Drawer::needDraw(Triangle* triangle){
	return true;
}

