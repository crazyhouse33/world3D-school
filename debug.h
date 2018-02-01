#ifdef DEBUG
#include <stdio.h>
extern void debug();
#define debug() debug()
#else 
#define debug() 
#endif

