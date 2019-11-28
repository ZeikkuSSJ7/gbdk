#include <stdio.h>

void checkDPadDiagonal(UINT8 jMovOne, UINT8 jMovTwo, UINT8 movX, UINT8 movY){
	while (joypad() & jMovTwo && joypad() & jMovOne) {
		animateKirby(jMovTwo);
		movDiagonal(movX, movY);
	}
}

void movDiagonal(UINT8 movX, UINT8 movY){
	player[0] += movX;
	player[1] += movY;
	moverSprite();
	delay(70);
}