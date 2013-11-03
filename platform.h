#include <stdio.h>

#define PLATFORMS_STRONG '='
#define PLATFORMS_WEAK '#'

#define PLATFORMS_WIDTH 3
#define PLATFORMS_HEIGHT 1
typedef enum bool {false,true} bool;

typedef struct velocity {
	int vx;
	int vy;
} velocity;

typedef struct platform {
	int x;
	int y;
	velocity v;
	bool strong;
} platform;
