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
	//glBegin(GL_TRIANGLES);
	glVertex3f(triangle->v1[0],triangle->v1[1], triangle->v1[2]);
	glVertex3f(triangle->v2[0],triangle->v2[1], triangle->v2[2]);
	glVertex3f(triangle->v3[0],triangle->v3[1], triangle->v3[2]);
	glEnd();
}

void Drawer::draw(Planet* planet){//TODO true recursion, CHANGE MODEL VIEW ACCORDING TO CENTER
for (int i=1 ; i<4;i++){
	draw(planet->getTriangle(i));
}
	

}
