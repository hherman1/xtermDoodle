#include "platform.h"
#include "keyboard.h"
#include "xterm_control.h"

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 45

static bool needPlatform();
static void generatePlatform();
static bool isUsed(int x,int y);
void newgame();
void updateWorld();



