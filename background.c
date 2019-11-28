#include <gb/gb.h>
#include "backgrounds/background_bricks.c"
#include "sprites/brick_background.c"

void scroll(){
    set_bkg_data(37, 7, brick_background);
    set_bkg_tiles(0, 0, 40, 18, background_bricks);
    SHOW_BKG;
}