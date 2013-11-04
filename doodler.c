#include <stdio.h>
#include "doodler.h"
#include "game.h"

static void drawDoodler(Doodler d) {
	xt_par2(XT_SET_ROW_COL_POS,1,1);
	xt_par2(XT_SET_ROW_COL_POS,d.y,d.x);
	xt_par0(XT_BG_RED);
	//printf("doodler");
	puts(DOODLER_SHAPE);
	xt_par0(XT_BG_DEFAULT);

}

Doodler updateDoodler(int key, Doodler *d) {
	d->x += d->v.vx;
	d->y += d->v.vy;
	d->v.vy ++;
	
	Platform *contact = getPlatform(d->x,d->y + d->v.vy);	
	printf("%p",contact);
	
	switch(key) {
		case KEY_LEFT:
			d->v.vx = -1 * MOVEMENT_SPEED;
			break;
		case KEY_RIGHT:
			
			d->v.vx = MOVEMENT_SPEED;
			//d->x += d->vx;//d->vx;
			//d->x ++;
			break;
		case KEY_UP:
			d->v.vy = -1 * JUMP_SPEED;
			break;
	}
	if(d->v.vy > 2) {
		d->v.vy = 2;
	}
	if(contact != NULL) {
		d->v.vy = -1 * JUMP_SPEED;
		d->y = contact->y - PLATFORMS_HEIGHT - 2;
	}
	if(d->x < 0 || d->x > SCREEN_WIDTH) {
		d->x = SCREEN_WIDTH - d->x;
	}
	if(d->y > SCREEN_HEIGHT) {
		d->alive = false;
	}
	

	drawDoodler(*d);
	return *d;
}

Doodler newDoodler() {
	Doodler d;
	d.x = 10;
	d.y = 10;
	d.v.vy = -1 * JUMP_SPEED;
	d.v.vx = 1;
	d.alive = true;
	return d;
}
