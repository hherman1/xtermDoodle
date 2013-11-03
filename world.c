#include "world.h"

static bool needPlatform(int time);
static void generatePlatform(int x,int y);
static char world[SCREEN_HEIGHT][SCREEN_WIDTH];
bool isUsed(int x,int y);

void newgame(){
	//init world array
	int row,col;	
	for(row = 0; row < SCREEN_HEIGHT; row++)
		for(col = 0; col < SCREEN_WIDTH; col++){
			world[row][col] = ' ';
		}
}
void updateWorld(){

}