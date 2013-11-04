#include "platform.h"
#include "keyboard.h"
#include "xterm_control.h"

#define GAMESPEED_FAST 10
#define GAMESPEED_SLOW 5
static bool isUsed(int x,int y);
static bool needPlatform();
static void generatePlatform(int row);
static void shiftWorldDown();
static void redisplay();
void newgame();
void updateWorld();
void setGameSpeed(int speed);
int getGameSpeed();

