#include "keyboard.h"
#include "xterm_control.h"

#define DOODLER_SHAPE " "
#define JUMP_SPEED 1
typedef struct Doodler {
	int x;
	int y;
	int vy;
} Doodler;
Doodler updateDoodler(int key, Doodler *d);
Doodler newDoodler();

