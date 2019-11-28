#include <gb/gb.h>
#include "sprites/kirby.c"
#include "sprites/kirbyJump.c"
#include "sprites/kirbyCrouch.c"

void sprites(){
	SPRITES_8x8;
	set_sprite_data(0, 4, kirby);
	set_sprite_data(4, 4, kirbymoving);
	set_sprite_data(8, 4, kirbymoving2);
	set_sprite_data(12, 4, kirbymoving3);
	set_sprite_data(16, 4, kirbyJump);
	set_sprite_data(20, 4, kirbyCrouch);
}