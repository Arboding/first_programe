#include "game_logic.h"
#include "view.h"
#include "settings.h"
#include "data.h"
#include <graphics.h>

int main() 
{
    initgraph(1000, 750);
    Music();
    playSoundEffect();
    handleMenuInput();
    closegraph();
    return 0;
}