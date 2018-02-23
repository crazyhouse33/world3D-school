#ifndef TRIANGLE
#define TRIANGLE
class Triangle{
	//public for pratical purpose
	public:
		Triangle(float* v1, float* v2, float* v3);
		float* v1;
		float* v2;
		float* v3;

		/**
		 * Function used to create 3 triangles from a triangle, take the midle of the triangle and return it normalized accordingly to distance */
		float* crack(float dist);
	private:
};
#endif

