#include "world.h"

#define SCREEN_WIDTH 70
#define SCREEN_HEIGHT 50

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
			world[row][col] = (col == SCREEN_WIDTH) ? '\n' : ' ';
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
	puts((char*)world);
	
	puts("F5 = quit");
	puts("F2 = fastspeed F3 = slowspeed");
	printf("GameSpeed = %s\n", (gameSpeed == GAMESPEED_FAST) ? "fast" : "slow");
}
static bool needPlatform(){
	if (tick >= gameSpeed){
		tick = 0;
	}
	return !tick;
}
static void generatePlatform(int row){
	int col = rand() % (SCREEN_WIDTH - PLATFORMS_WIDTH);
	Platform p;
	p.x = col;
	p.y = row;
	p.strong = 1;
	p.v.vx = p.v.vy = 0;
	int i,j;
	for(i = 0; i < PLATFORMS_HEIGHT; i++){
		for(j = 0; j < PLATFORMS_WIDTH; j++){
			world[row+i][col+j] = (p.strong) ? PLATFORMS_STRONG : PLATFORMS_WEAK;
		}
	}
}
bool isUsed(int x,int y){
	return true;
}

static void shiftWorldDown(){
	int row,col;
	for(row = SCREEN_HEIGHT-1; row > 0; row--)
		for(col = 0; col < SCREEN_WIDTH; col++){
			world[row][col] = world[row-1][col];
		}
	for(col = 0; col < SCREEN_WIDTH; col++)
		world[0][col] = ' ';
	if(needPlatform())
		generatePlatform(0);
}

void setGameSpeed(int speed){
	if (speed == GAMESPEED_FAST || speed == GAMESPEED_SLOW)
		gameSpeed = speed;
}
int getGameSpeed(){
	return gameSpeed;
}
