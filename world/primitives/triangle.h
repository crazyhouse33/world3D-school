#ifndef TRIANGLE
#define TRIANGLE
class Triangle{
	//public for pratical purpose
	public:
		Triangle(float* v1, float* v2, float* v3);
		float* vertex1;
		float* vertex2;
		float* vertex3;
		/**
		 * Function used to create 3 triangles from a triangle and a "break"
		 * point: imagine a triangle. Trace a line between the 3 allready 
		 * existings vertex and the so called "break" point to obtain 3 
		 * new triangles. That's what this function do
		 * */
		Triangle** crack(double* vertex);
	private:
};
#endif

