#include <stdio.h>
#include <sys/time.h>
#include "unistd.h"
#include "world.h"
#include "doodler.h"

#define FRAME_LENGTH 100

unsigned long long currentTime(struct timeval t) {
	return (unsigned long long) 1000 * t.tv_sec + (unsigned long long) t.tv_usec/1000;
}

void main(){
	newgame();
	struct timeval t;
	gettimeofday(&t,NULL);
	
	int distance = 0;
	
	unsigned long long time = currentTime(t);
	unsigned long long updateTime = time + FRAME_LENGTH;
	
	Doodler doodles = newDoodler();

	while(doodles.alive){
		int i;
		int c = getkey();
		
		updateWorld(doodles, &distance);
		updateDoodler(c,&doodles);
		if(c == KEY_F5 || c == 'q') {
			getkey_terminate();
			return;
		}
		else if(c == KEY_F2 || c == '2') setGameSpeed(GAMESPEED_FAST);
		else if(c == KEY_F3 || c =='3') setGameSpeed(GAMESPEED_SLOW);
		while(updateTime > time) {
			gettimeofday(&t,NULL);
			time = currentTime(t);
			
		}
		updateTime = time + FRAME_LENGTH;
	}
	
	xt_par0(XT_CLEAR_SCREEN);
	xt_par0(XT_BG_DEFAULT);
	printf("Game over! Your score was: %i\n", distance);
	usleep(1000000);
	int cc;
	getkey_terminate();
}
