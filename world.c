#include "world.h"

static char world[SCREEN_HEIGHT][SCREEN_WIDTH];
static Platform* platforms;
static int  numPlatforms = 0;



void newgame(){
	//init world array
	int row,col;	
	for(row = 0; row < SCREEN_HEIGHT; row++)
		for(col = 0; col < SCREEN_WIDTH; col++){
			world[row][col] = '-';
		}
}
void updateWorld(){
	if(needPlatform())
		generatePlatform();
	//update display
	xt_par0(XT_CLEAR_SCREEN);
	int row,col;
	for(row = 0; row < SCREEN_HEIGHT; row++)
		for(col = 0; col < SCREEN_WIDTH; col++){
			printf("%c", world[row][col]);
		}
}

static bool needPlatform(){
	return 1;
}
static void generatePlatform(){

}
static bool isUsed(int x,int y);