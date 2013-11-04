
#include "keyboard.h"
#include "xterm_control.h"
#include "platform.h"

#define DOODLER_SHAPE " "
#define JUMP_SPEED 6
#define MOVEMENT_SPEED 2

#define PF_DEBUG 0

#ifndef DOODLER_H
#define DOODLER_H

typedef struct Doodler {
	int x;
	int y;
	bool alive;
	Velocity v;
} Doodler;
Doodler updateDoodler(int key, Doodler *d);
Doodler newDoodler();
#endif
