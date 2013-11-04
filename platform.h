#include <stdio.h>

#define PLATFORMS_STRONG '='
#define PLATFORMS_WEAK '#'

#define PLATFORMS_WIDTH 10
#define PLATFORMS_HEIGHT 2
typedef enum bool {false,true} bool;

typedef struct Velocity {
	int vx;
	int vy;
} Velocity;

typedef struct Platform {
	int x;
	int y;
	Velocity v;
	bool strong;
} Platform;
