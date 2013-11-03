#include <stdio.h>
#include "world.h"
##include "unistd.h"

void main(){
	newgame();
	while(1){

		updateWorld();
		usleep(500);
	}
}
