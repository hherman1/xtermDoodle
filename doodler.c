#include "doodler.h"

Doodler updateDoodler(int key, Doodler *d) {
	d->y += d->vy;
	d->vy --;
	
	switch(key) {
		case KEY_LEFT:
			d->x--;
			break;
		case KEY_RIGHT:
			d->x++;
			break;
	}
	if(isUsed(d->x,d->y)) {
		d->vy = JUMP_SPEED;
	}
	drawDoodler(*d);
	return *d;
}
static void drawDoodler(Doodler d) {
	xt_par2(XT_SET_ROW_COL_POS,d.x,d.y);
}
