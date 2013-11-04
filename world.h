#include "platform.h"
#include "keyboard.h"
#include "xterm_control.h"

static bool isUsed(int x,int y);
static bool needPlatform();
static void generatePlatform(int row);
static void shiftWorldDown();
static void redisplay();
void newgame();
void updateWorld();



