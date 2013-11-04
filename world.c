#include "world.h"

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 25
#define GAMESPEED_FAST 5
#define GAMESPEED_SLOW 3
static char world[SCREEN_HEIGHT][SCREEN_WIDTH+1];
static Platform* platforms;
static int  numPlatforms = 0;
static int tick = 0;
static int gameSpeed= GAMESPEED_SLOW;
void newgame(){
	//init world array
	int row,col;	
	for(row = 0; row < SCREEN_HEIGHT; row++){
		for(col = 0; col < SCREEN_WIDTH+1; col++){
			world[row][col] = (col == SCREEN_WIDTH) ? '\n' : '-';
		}
		if(row % gameSpeed == gameSpeed-1) // makes bottom row have platform always
			generatePlatform(row);
	}
	redisplay();
}
void updateWorld(){
	shiftWorldDown();
	redisplay();
	tick++;
}
static void redisplay(){
	xt_par2(XT_SET_ROW_COL_POS,1,1);
	xt_par0(XT_CLEAR_SCREEN);
	xt_par2(XT_SET_ROW_COL_POS,1,1);
	printf((char*)world);
}
static bool needPlatform(){
	return (tick > gameSpeed);
}
static void generatePlatform(int row){
	int col = rand() % (SCREEN_WIDTH - PLATFORMS_HEIGHT);
	Platform p;
	p.x = col;
	p.y = row;
	p.strong = 1;
	p.v.vx = p.v.vy = 0;
	int i;
	for(i = 0; i < 3; i++){
		world[row][col+i] = (p.strong) ? PLATFORMS_STRONG : PLATFORMS_WEAK;
	}
}
static bool isUsed(int x,int y);

static void shiftWorldDown(){
	int row,col;
	for(row = SCREEN_HEIGHT-1; row > 1; row--)
		for(col = 0; col < SCREEN_WIDTH; col++){
			world[row][col] = world[row-1][col];
		}
	for(col = 0; col < SCREEN_WIDTH; col++)
		world[0][1] = ' ';
	if(needPlatform())
		generatePlatform(0);
}
