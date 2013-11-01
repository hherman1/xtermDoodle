#include <stdio.h>
typedef struct velocity {
	int vx;
	int vy;
} velocity;

typedef struct platform {
	int x;
	int y;
	velocity v;
} platform;
