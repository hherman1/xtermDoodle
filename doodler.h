
#include "keyboard.h"
#include "xterm_control.h"
#include "platform.h"
#include "world.h"

#define DOODLER_SHAPE " "
#define JUMP_SPEED 4
#define MOVEMENT_SPEED 2

typedef struct Doodler {
	int x;
	int y;
	bool alive;
	Velocity v;
} Doodler;
Doodler updateDoodler(int key, Doodler *d);
Doodler newDoodler();

