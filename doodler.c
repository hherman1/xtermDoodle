#include "doodler.h"
static void drawDoodler(Doodler d) {
	xt_par2(XT_SET_ROW_COL_POS,d.y,d.x);
	xt_par0(XT_BG_RED);
	puts(DOODLER_SHAPE);
	xt_par0(XT_BG_DEFAULT);
}

Doodler updateDoodler(int key, Doodler *d) {
	d->y += d->vy;
	d->vy ++;
	
	switch(key) {
		case KEY_LEFT:
			d->x--;
			break;
		case KEY_RIGHT:
			d->x++;
			break;
		case KEY_UP:
			d->vy = -5;
			break;
	}
	if(d->vy > 2) {
		d->vy = 2;
	}
	drawDoodler(*d);
	return *d;
}
Doodler newDoodler() {
	Doodler d;
	d.x = 1;
	d.y = 1;
	d.vy = 0;
	return d;
}
