#include "keyboard.h"
#include "xterm_control.h"
#include "world.h"

typedef struct Doodler {
	int x;
	int y;
	int vy;
}
void updateDoodler(int key, Doodler d);

