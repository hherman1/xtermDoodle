#include "platform.h"
#include "keyboard.h"
#include "xterm_control.h"

#define GAMESPEED_FAST 5
#define GAMESPEED_SLOW 3
bool isUsed(int x,int y);
static bool needPlatform();
static void generatePlatform(int row);
static void shiftWorldDown();
static void redisplay();
void newgame();
void updateWorld();
void setGameSpeed(int speed);
int getGameSpeed();

