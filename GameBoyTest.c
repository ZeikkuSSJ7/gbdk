#include <stdio.h>
#include <gb/gb.h>
#include "sprites.c"
void kirbyQuieto(){
	set_sprite_tile(0, 0);
	set_sprite_tile(1, 1);
	set_sprite_tile(2, 2);
	set_sprite_tile(3, 3);
	return;
}
void kirbyMueve1(){
	set_sprite_tile(0, 4);
	set_sprite_tile(1, 5);
	set_sprite_tile(2, 6);
	set_sprite_tile(3, 7);
	return;
}
void kirbyMueve2(){
	set_sprite_tile(0, 8);
	set_sprite_tile(1, 9);
	set_sprite_tile(2, 10);
	set_sprite_tile(3, 11);
	return;
}
void kirbyMueve3(){
	set_sprite_tile(0, 12);
	set_sprite_tile(1, 13);
	set_sprite_tile(2, 14);
	set_sprite_tile(3, 15);
	return;
}
void moverSprite(int x, int y){
	move_sprite(0, x, y);
	move_sprite(1, x, y + 8);
	move_sprite(2, x + 8, y);
	move_sprite(3, x + 8, y + 8);
	return;
}
void main(){
	int x = 55;
	int y = 75;
	SPRITES_8x8;
	set_sprite_data(0, 4, kirby);
	set_sprite_data(4, 4, kirbymoving);
	set_sprite_data(8, 4, kirbymoving2);
	set_sprite_data(12, 4, kirbymoving3);
	kirbyQuieto();
	moverSprite(x, y);
	SHOW_SPRITES;

	// box(0, 0, 159, 143, M_NOFILL);
	while(1){

		while (joypad() == J_RIGHT) {
			kirbyMueve1();
			x++;
			x++;
			x++;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			x++;
			x++;
			x++;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve3();
			x++;
			x++;
			x++;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			x++;
			x++;
			x++;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve1();
			x++;
			x++;
			x++;
			moverSprite(x, y);
			delay(70);
		}

		while (joypad() == J_LEFT) {
			kirbyMueve1();
			x--;
			x--;
			x--;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			x--;
			x--;
			x--;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve3();
			x--;
			x--;
			x--;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			x--;
			x--;
			x--;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve1();
			x--;
			x--;
			x--;
			moverSprite(x, y);
			delay(70);
		}

		while (joypad() == J_UP) {
			kirbyMueve1();
			y--;
			y--;
			y--;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			y--;
			y--;
			y--;
			moverSprite(x, y);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve3();
			y--;
			y--;
			y--;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			y--;
			y--;
			y--;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve1();
			y--;
			y--;
			y--;
			moverSprite(x, y);
			delay(70);
		}

		while (joypad() == J_DOWN) {
			kirbyMueve1();
			y++;
			y++;
			y++;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			y++;
			y++;
			y++;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve3();
			y++;
			y++;
			y++;
			moverSprite(x, y);
			delay(70);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve2();
			delay(70);
			y++;
			y++;
			y++;
			moverSprite(x, y);
			if (joypad() == 0) {
				break;
			}
			kirbyMueve1();
			delay(70);
			y++;
			y++;
			y++;
			moverSprite(x, y);
		}

		if (joypad() & J_UP) {
			if(joypad() & J_RIGHT){
				set_sprite_tile(0, 1);
				y--;
				x++;
				move_sprite(0, x, y);
				delay(10);
			}
		}

		if (joypad() & J_UP) {
			if (joypad() & J_LEFT) {
				set_sprite_tile(0, 1);
				y--;
				x--;
				move_sprite(0, x, y);
				delay(10);	
			}
		}

		if (joypad() & J_DOWN) {
			if (joypad() & J_LEFT) {
				set_sprite_tile(0, 1);
				y++;
				x--;
				move_sprite(0, x, y);
				delay(10);
			}
		}

		if (joypad() & J_DOWN) {
			if (joypad() & J_RIGHT) {
				set_sprite_tile(0, 1);
				y++;
				x++;
				move_sprite(0, x, y);
				delay(10);
			}
		}

		if (joypad() == 0) {
			kirbyQuieto();
		}

		if (joypad() == J_START) {
			delay(70);
			printf("PAUSE");
			waitpad(J_START);
			delay(70);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}
		
	}
}