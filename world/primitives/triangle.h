#ifndef TRIANGLE
#define TRIANGLE
class Triangle{
	//public for pratical purpose
	public:
	vec3* vertex1;
	vec3* vertex2;
	vec3* vertex3;
	/**
	 * Function used to create 3 triangles from a triangle and a "break"
	 * point: imagine a triangle. Trace a line between the 3 allready 
	 * existings vertex and the so called "break" point to obtain 3 
	 * new triangles. That's what this function do
	 * */
	Triangle** crack(double* vertex);
}


