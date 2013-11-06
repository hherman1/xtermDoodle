#include "platform.h"
#include "keyboard.h"
#include "xterm_control.h"
#include "doodler.h"
#include "game.h"

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
void updateWorld(Doodler *d, int *score);
void setGameSpeed(int speed);
int getGameSpeed();
bool isUsed(int x,int y);
