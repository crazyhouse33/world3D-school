
/*This implementation of three use way less memory than the standard pointer chained tree (economise 3 pointers for each triangle). The other advantage is that the iteration in the tree is always from left to right. We may use that later to use disk more conveniently. Another usefull thing is the possiblity of iterating over neghtboursTriangle (tree POV), making it possible to iterate over any stage of the tree whitout more memory alloc (which is usefull cause we dispose a quick way of getting all last level triangles, which help, for instances, collisions detection). We also get an easy way to get any ancestor of a triangle.Also, this is more cache friendly 
 *
 *
 * The cost is that it doesnt abstract all the logic for user class
 * Also, it's not a normal ternary tree since we have 4 roots. 
 */
#ifndef TRIANGLETREE
#define TRIANGLETREE
#include "triangle.h"
class PlanetTree{

	public:

		PlanetTree(int depth, float radius, int sphericalAspect, int uniformity, int variationStrenght );//TODO add 9(max) planet float input
		//TODO unsigned int?
		int getFirstSonIndex(int i);
		int getSecondSonIndex(int i);
		int getThirdSonIndex(int i);

		int getLeft(int i);
		int getRight(int i);


		//int getAncestor(int i, int generation);//easy, may be needed one day

		inline Triangle* operator[](int i){
			return &array[i];
		}

	
//todo [] operator 		
	private:
	       	Triangle* array;


};
#endif
