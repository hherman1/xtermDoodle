#include "platform.h"
#include "keyboard.h"
#include "xterm_control.h"

#define SCREEN_WIDTH 70
#define SCREEN_HEIGHT 50
#define MAX_PLATFORMS 50
#define GAMESPEED_FAST 20
#define GAMESPEED_SLOW 10

static bool needPlatform();
static bool contains(Platform p, int x, int y);
static void generatePlatform(int row);
static void shiftWorldDown();
static void redisplay();
static void blankWorld();
static void updatePlatform(Platform* p);
static void removePlatform(int pos);
Platform* getPlatform(int x, int y);
void newgame();
void updateWorld();
void setGameSpeed(int speed);
int getGameSpeed();
bool isUsed(int x,int y);
