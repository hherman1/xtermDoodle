#include "world.h"

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 25
#define GAMESPEED_FAST 10
#define GAMESPEED_SLOW 5
static char world[SCREEN_HEIGHT][SCREEN_WIDTH+1];
static Platform* platforms;
static int  numPlatforms = 0;
static int tick = 0;
static int gameSpeed= GAMESPEED_FAST;
void newgame(){
	//init world array
	int row,col;	
	for(row = 0; row < SCREEN_HEIGHT; row++)
		for(col = 0; col < SCREEN_WIDTH+1; col++){
			world[row][col] = (col == SCREEN_WIDTH) ? '\n': '-';
		}
}
void updateWorld(){
	shiftWorldDown();
	//update display
	xt_par2(XT_SET_ROW_COL_POS,1,1);
	xt_par0(XT_CLEAR_SCREEN);
	xt_par2(XT_SET_ROW_COL_POS,1,1);
	printf((char*)world);
	tick++;
}

static bool needPlatform(){
	return (tick > gameSpeed);
}
static void generatePlatform(){

}
static bool isUsed(int x,int y);

static void shiftWorldDown(){
	if(needPlatform())
		generatePlatform();
}
