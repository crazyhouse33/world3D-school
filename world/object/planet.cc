#include <planet.h>

/*
 * first phase:
 * constructing the 4 triangles forming the tetrahedron envelloped by the sphere formed by
 * center and radius;
 *
 * second phase:
 * Constructing relatively spherical object (we could skip this step to make asteroids).
 * To do so we use Triangle::Crack() on the intersection betwen the sphere and the 
 * perpendiculaire line of the triangle's surface
 * 
 * third phase:
 * We add randomness to emulate relief. For that we crack the triangle on a random point
 * on the perpendicular. We need to mess around whit that randomness to creates realistic
 * reliefs.
 * 
 * We generate the mesh while constructing the planet
 * */

//TODO ajouter parametre sphericite puis interpoler phase 2 et 3 selon la valeur de ce truc?


