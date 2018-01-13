#ifndef TRIANGLE
#define TRIANGLE
class Triangle{
	//public for pratical purpose
	public:
	double* vertex1;
	double* vertex2;
	double* vertex3;
	void* texture;
	/**
	 * Function used to create 3 triangles from a triangle and a "break"
	 * point: imagine a triangle. Trace a line betwen the 3 allready 
	 * existings vertex and the so called "break" point to obtain 3 
	 * new triangles. That's what this function do
	 * */
	Triangle** crack(double* vertex);
}


