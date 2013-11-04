#include "world.h"

static char world[SCREEN_HEIGHT][SCREEN_WIDTH+1];
static Platform platforms[MAX_PLATFORMS];
static int  numPlatforms = 0;
static int tick = 0;
static int gameSpeed= GAMESPEED_SLOW;
void newgame(){
	blankWorld();
	//initial platforms
	int row;
	for(row = 0; row < SCREEN_HEIGHT; row++){
		if(row % gameSpeed == gameSpeed-PLATFORMS_HEIGHT) // makes bottom row have platform always
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
	//clear
	xt_par2(XT_SET_ROW_COL_POS,1,1);
	xt_par0(XT_CLEAR_SCREEN);
	xt_par2(XT_SET_ROW_COL_POS,1,1);
	blankWorld();
	//update platforms
	int i;
	for(i = 0; i < numPlatforms; i++){
		updatePlatform(platforms[i]);
	}
	//display world
	puts((char*)world);
	//instruction messages
	puts("F5 or q = quit");
	puts("F2 or 2 = fastspeed 	F3 or 3 = slowspeed");
	printf("GameSpeed = %s\n", (gameSpeed == GAMESPEED_FAST) ? "fast" : "slow");
}
static void blankWorld(){
	int row,col;	
	for(row = 0; row < SCREEN_HEIGHT; row++){
		for(col = 0; col < SCREEN_WIDTH+1; col++){
			world[row][col] = (col == SCREEN_WIDTH) ? '\n' : ' ';
		}
	}
}
static void updatePlatform(Platform p){
	p.x = p.v.vx;
	//p.y += p.v.vy;
	if(p.x > SCREEN_WIDTH){
		p.x = SCREEN_WIDTH - (p.x - SCREEN_WIDTH);
		p.v.vx *= -1;
	}else if(p.x < 0){
		p.x = 0 + (0 - p.x);
		p.v.vx *= -1;
	}
	//insert in platforms array
	int i,j;
	for(i = 0; i < PLATFORMS_HEIGHT; i++){
		for(j = 0; j < PLATFORMS_WIDTH; j++){
			world[p.y+i][p.x+j] = (p.strong) ? PLATFORMS_STRONG : PLATFORMS_WEAK;
		}
	}
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
	p.v.vy = 0;
	p.v.vx = 2;//(rand() % 2) ? 0 : gameSpeed / 8;

	platforms[numPlatforms++] = p;
	updatePlatform(p);
}
bool isUsed(int x,int y){
	return true;
}

static void removePlatform(int pos){
	for(pos; pos < numPlatforms; pos++)
		platforms[pos] = platforms[pos+1];
	numPlatforms--;
}
static void shiftWorldDown(){
	int row,col;
	int i;
	for(i = 0; i < numPlatforms; i++){
		//Platform p = platforms[i];
		if(++(platforms[i].y) > SCREEN_HEIGHT - PLATFORMS_HEIGHT)
			removePlatform(i);
	}
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
