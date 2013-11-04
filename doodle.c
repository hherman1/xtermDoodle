#include <stdio.h>
#include "unistd.h"
#include "world.h"

void main(){
	newgame();
	while(1){
		//int c;
		int c = getkey();
		//while ((c = getkey()) == KEY_NOTHING) ;
		if(c == KEY_F5 || c == 'q') break;
		else if(c == KEY_F2 || c == 'a') setGameSpeed(GAMESPEED_FAST);
		else if(c == KEY_F3) setGameSpeed(GAMESPEED_SLOW);
		updateWorld();
		int i;
		for(i = 0; i <= 15 / getGameSpeed(); i++)
			usleep(100000);
	}
	getkey_terminate();
}
