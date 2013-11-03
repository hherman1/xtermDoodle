#include "world.h"


#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 45
#define GAMESPEED_FAST 10
#define GAMESPEED_SLOW 5
static char world[SCREEN_HEIGHT][SCREEN_WIDTH];
static Platform* platforms;
static int  numPlatforms = 0;
static int tick = 0;
static int gameSpeed= GAMESPEED_FAST;
void newgame(){
	//init world array
	int row,col;	
	for(row = 0; row < SCREEN_HEIGHT; row++)
		for(col = 0; col < SCREEN_WIDTH; col++){
			world[row][col] = '-';
		}
}
void updateWorld(){
	shiftWorldDown();
	//update display
	xt_par0(XT_CLEAR_SCREEN);
	int row,col;
	xt_par2(XT_SET_ROW_COL_POS,row=0,col=0);
	for(row; row < SCREEN_HEIGHT; row++)
		for(col; col < SCREEN_WIDTH; col++){
			printf("%c", world[row][col]);
		}
	tick++;
}

static bool needPlatform(){
	return (tick > gameSpeed);
}
static void generatePlatform(){

}
static bool isUsed(int x,int y);

static shiftWorldDown(){
	if(needPlatform())
		generatePlatform();
}