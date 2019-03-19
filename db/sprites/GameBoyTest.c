#include <stdio.h>
#include <gb/gb.h>
#include "sprites/smile.c"


void main(){
	printf("  o hallo beutiful\n       comrad\n\n");
	printf("  hau r u wir fain\n\n");
	printf("   we pretty an smol\n\n\n\n\n\n");
	// printf(" do u mak vidyu gam");

	SPRITES_8x8;

	set_sprite_data(0, 6, smile);
	set_sprite_tile(0, 0);
	set_sprite_tile(1, 1);
	set_sprite_tile(2, 2);
	set_sprite_tile(3, 3);
	set_sprite_tile(4, 4);
	move_sprite(0, 75, 75);
	move_sprite(1, 75, 83);
	move_sprite(2, 83, 75);
	move_sprite(3, 83, 83);

	set_sprite_data(6, 4, frown);
	set_sprite_tile(6, 0);
	set_sprite_tile(7, 2);
	set_sprite_tile(8, 6);
	set_sprite_tile(9, 7);
	move_sprite(6, 95, 75);
	move_sprite(7, 103, 75);
	move_sprite(8, 95, 83);
	move_sprite(9, 103, 83);

	SHOW_SPRITES;
	while(1){

		//move_sprite(0, 75, 65);
		//move_sprite(1, 83, 65);
		//move_sprite(2, 95, 85);
		//move_sprite(3, 103, 85);
		set_sprite_tile(2, 4);
		set_sprite_tile(3, 5);
		delay(500);
		set_sprite_tile(2, 2);
		set_sprite_tile(3, 3);

		set_sprite_tile(6, 8);
		set_sprite_tile(7, 9);
		delay(500);
		set_sprite_tile(6, 0);
		set_sprite_tile(7, 2);
		//move_sprite(0, 75, 75);
		//move_sprite(1, 83, 75);
		//move_sprite(2, 95, 75);
		//move_sprite(3, 103, 75);
	}
	

}