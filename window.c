#include <gb/gb.h>
#include "windows/window_title.c"

void window(){
    set_win_tiles(0, 0, 12, 1, window_title);
    move_win(7, 136);
    SHOW_WIN;
}