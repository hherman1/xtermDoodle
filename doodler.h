#include "keyboard.h"
#include "xterm_control.h"
#include "world.h"

#define JUMP_SPEED 1

typedef struct Doodler {
	int x;
	int y;
	int vy;
}
void updateDoodler(int key, Doodler d);


