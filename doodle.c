#include <stdio.h>
#include "unistd.h"
#include "world.h"

void main(){
	newgame();
	while(1){
		//int c;
		//while ((c = getkey()) == KEY_NOTHING) ;
		updateWorld();
		int i;
		for(i = 0; i <= 30 / getGameSpeed(); i++){
			int c = getkey();
			if(c == KEY_F5 || c == 'q') {
				getkey_terminate();
				return;
			}
			else if(c == KEY_F2 ) setGameSpeed(GAMESPEED_FAST);
			else if(c == KEY_F3) setGameSpeed(GAMESPEED_SLOW);
			usleep(50000);
		}
	}
	getkey_terminate();
}
