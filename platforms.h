#include <stdio.h>
struct velocity {
	int vx;
	int vy;
};
typedef struct velocity velocity;

typedef struct platform {
	int x;
	int y;
	velocity v;
} platform;
