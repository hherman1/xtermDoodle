#include <stdio.h>
#include "unistd.h"
#include "world.h"

void main(){
	newgame();
	//usleep(50000);
	//updateWorld();
	while(1){
		//int c;
		int c = getkey();
		//while ((c = getkey()) == KEY_NOTHING) ;
		if(c == KEY_F5) break;
		updateWorld();

		usleep(100000);
		usleep(100000);
		usleep(100000);
		usleep(100000);
		usleep(100000);
	}
	getkey_terminate();
}
