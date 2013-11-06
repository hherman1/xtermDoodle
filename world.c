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
void updateWorld(Doodler *d, int *score){
	while(d->y < SCREEN_HEIGHT/3) {
		*score = *score + 1;
		d->y++;
		shiftWorldDown();
		tick++;
	}
		redisplay();
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
		updatePlatform(&(platforms[i]));
	}
	//puts((char*)world);
	//instruction messages
	xt_par2(XT_SET_ROW_COL_POS,SCREEN_HEIGHT+1,0);
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
static void updatePlatform(Platform* p){
	p->x += p->v.vx;
	//p->y += p->v.vy;
	int max_x = SCREEN_WIDTH - PLATFORMS_WIDTH;
	if(p->x >= (max_x)) {
		p->x = max_x - (p->x - max_x);
		p->v.vx *= -1;
	}else if(p->x < 0){
		p->x = 0 + (0 - p->x);
		p->v.vx *= -1;
	}
	//insert in platforms array
	xt_par0(p->color);
	int i,j;
	for(i = 0; i < PLATFORMS_HEIGHT; i++){
		for(j = 0; j < PLATFORMS_WIDTH; j++){
			int row = p->y+i, col = p->x+j;
			//prints
			xt_par2(XT_SET_ROW_COL_POS,row,col);
			putchar(world[row][col] = (p->strong) ? PLATFORMS_STRONG : PLATFORMS_WEAK);
		}
	}
	xt_par0(XT_CH_NORMAL);
}
static bool needPlatform(){
	if (tick >= gameSpeed){
		tick = 0;
	}
	return !tick;
}
static void generatePlatform(int row){
	Platform p;
	p.x = rand() % (SCREEN_WIDTH - PLATFORMS_WIDTH);
	p.y = row;
	p.strong = 1;
	p.v.vy = 0;
	p.v.vx = (rand() % 2) ? 0 : gameSpeed / GAMESPEED_SLOW;
	p.color = (p.v.vx) ? XT_CH_BLUE : XT_CH_GREEN;
	if(!p.strong)
		p.color = XT_CH_WHITE;
	platforms[numPlatforms++] = p;
	updatePlatform(&p);
}
Platform* getPlatform(int x, int y) {
	Platform *search = platforms;
	Platform *ans = NULL;
	int i;
	for(i = 0; i < numPlatforms;i++) {
		if(contains(*search,x,y)) {
			
			ans = search;
			break;
		}
		search++;
	}
	return ans;
}
static bool contains(Platform p, int x, int y) {
	return (x <= p.x + PLATFORMS_WIDTH && x >= p.x)  && ( y >= p.y - PLATFORMS_HEIGHT && y <= p.y);
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
