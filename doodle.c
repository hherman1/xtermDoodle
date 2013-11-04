#include <stdio.h>
#include "unistd.h"
#include "world.h"
#include "doodler.h"

void main(){
	newgame();
	while(1){
		//int c;
		//while ((c = getkey()) == KEY_NOTHING) ;
		updateWorld();
		updateDoodler(c);
		int i;
		for(i = 0; i < (6 * GAMESPEED_FAST/getGameSpeed()); i++){
			int c = getkey();
			if(c == KEY_F5 || c == 'q') {
				getkey_terminate();
				return;
			}
			else if(c == KEY_F2 || c == '2') setGameSpeed(GAMESPEED_FAST);
			else if(c == KEY_F3 || c =='3') setGameSpeed(GAMESPEED_SLOW);
			usleep(25000);
		}
	}
	getkey_terminate();
}
