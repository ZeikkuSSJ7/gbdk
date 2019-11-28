#include <stdio.h>
#include <gb/gb.h>
#include "movement.c"
#include "background.c"
#include "window.c"
#include "sprites.c"
#include <gb/font.h>

void initializeFonts(){
	font_t min_font;
	font_init();
	min_font = font_load(font_min);
	font_set(min_font);
}

void initializeSoundRegisters(){
	NR52_REG = 0x80; // enciende el sonido
	NR50_REG = 0x77; // sube el volumen de los canales al maximo
	NR51_REG = 0xFF; // selecciona que canales se usan, 0x77 son todos 
}

void initialize(){
	initializeFonts();
	initializeSoundRegisters();
	scroll();
	window();
	sprites();
	changeKirbyTileSet(0, RIGHT);
	moverSprite(player[0], player[1]);
	SHOW_SPRITES;
	wait_vbl_done();
}

void main(){
	initialize();
	while(1) {
		UBYTE joypadState = joypad();
		if (joypadState == 0){
			if (flipped)
				changeKirbyTileSet(0, LEFT);
			else
				changeKirbyTileSet(0, RIGHT);
			step = 1;
			next = 1;
			continue;
		} else{
			if (joypadState & J_RIGHT){
				moveRight();
			} else if (joypadState & J_LEFT){
				moveLeft();
			} else if (joypadState & J_START){
				pause();
			} else if (joypadState & J_A){
				jump();
			} else if (joypadState & J_DOWN){
				if (flipped)
					crouch(1, LEFT);
				else 
					crouch(1, RIGHT);
			} else if (joypadState & J_B){
				noise();
			}
		}
		wait_vbl_done();
	}
}