#include <stdio.h>
#include "unistd.h"
#include "world.h"

void main(){
	newgame();
	while(1){
		int c = getkey();
		if(c == KEY_F5) break;
		updateWorld();
		usleep(500);
	}
	getkey_terminate();
}
