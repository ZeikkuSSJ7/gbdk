#include <stdio.h>
#include <gb/gb.h>
#include "sound.c"

#define DELAY_ANIMATION_WALK 40
#define MOVEMENT_WALKING 3
#define MOVEMENT_BACKGROUND 3
#define LEFT 2
#define RIGHT 0
#define jumpMovement 1
#define MAX_BOUNDS 102
#define MIN_BOUNDS 39
#define DELAY_CROUCH 70

unsigned char pause_title[] =
{
  	0x1B, 0x0C, 0x20, 0x1E, 0x10
};

unsigned char pause_void[] = 
{
	0x00, 0x00, 0x00, 0x00, 0x00
};

UINT8 player [] = {MIN_BOUNDS, 92};
UINT8 step = 1;
UINT8 next = 1;
UINT8 flipped = 0;
UINT8 inBounds = 1;
UINT8 scrollDirection = 0;


void backwards(UINT8 jMov){
	if (jMov & J_LEFT && !flipped){
		set_sprite_prop(0, S_FLIPX);
		set_sprite_prop(1, S_FLIPX);
		set_sprite_prop(2, S_FLIPX);
		set_sprite_prop(3, S_FLIPX);
		flipped = 1;
	} else if (flipped && !(jMov & J_LEFT)) {
		set_sprite_prop(0, 0);
		set_sprite_prop(1, 0);
		set_sprite_prop(2, 0);
		set_sprite_prop(3, 0);

		flipped = 0;
	}
}

int checkJoyPad(UINT8 jButton){
	if (joypad() & jButton)
		return 0;
	return 1;
}

void changeKirbyTileSet(UINT8 tileSet, UINT8 direction){
	set_sprite_tile(0 + direction, 0 + (4 * tileSet));
	set_sprite_tile(1 + direction, 1 + (4 * tileSet));
	set_sprite_tile(2 - direction, 2 + (4 * tileSet));
	set_sprite_tile(3 - direction, 3 + (4 * tileSet));
	return;
}

void setJumpPos(UINT8 i, UINT8 direction){
	set_sprite_tile(0 + direction, 0 + i);
	set_sprite_tile(1 + direction, 1 + i);
	set_sprite_tile(2 - direction, 2 + i);
	set_sprite_tile(3 - direction, 3 + i);
	return;
}

void moverSprite(){
	move_sprite(0, player[0], player[1]);
	move_sprite(1, player[0], player[1] + 8);
	move_sprite(2, player[0] + 8, player[1]);
	move_sprite(3, player[0] + 8, player[1] + 8);
	return;
}

void crouch(UINT8 delayAnim, UINT8 direction){
	set_sprite_tile(0 + direction, 20);
	set_sprite_tile(1 + direction, 21);
	set_sprite_tile(2 - direction, 22);
	set_sprite_tile(3 - direction, 23);
	delay(delayAnim);
}

void setBounds(UINT8 mov){
	if (player[0] >= MAX_BOUNDS && (mov == MOVEMENT_WALKING || mov == jumpMovement)){
		scrollDirection = 1;
		inBounds = 0;
	} else if (player[0] <= MIN_BOUNDS && (mov == -MOVEMENT_WALKING || mov == -jumpMovement)){
		scrollDirection = 0;
		inBounds = 0;
	} else {
		inBounds = 1;
		scrollDirection = -1;
	}
}

void movLineal(UINT8 mov, int inBounds){
	if (inBounds == 1){
		player[0] += mov;
	}
	moverSprite();
}

void animateKirby(UINT8 movingBackwards){
	backwards(movingBackwards);
	if (flipped)
		changeKirbyTileSet(step, LEFT);
	else
		changeKirbyTileSet(step, RIGHT);
	step += next;
	if (step == 3 || step == 1)
		next *= -1;
}

void moveWhileJump(){
	if (joypad() & J_RIGHT){
		setBounds(MOVEMENT_WALKING);
		if (scrollDirection == 1){
			scroll_bkg(MOVEMENT_BACKGROUND, 0);
		} else {
			player[0] += MOVEMENT_WALKING;
		}
	} else if (joypad() & J_LEFT){
		setBounds(-MOVEMENT_WALKING);
		if (scrollDirection == 0){
			scroll_bkg(-MOVEMENT_BACKGROUND, 0);
		} else {
			player[0] -= MOVEMENT_WALKING;
		}
	}
	moverSprite();
}

void jump(){
	UINT8 originalY = player[1] + 8;
	int max = 16;
	if (joypad() & J_A){
		int pos = max;
		soundJump();
		if (flipped){
			setJumpPos(16, LEFT);
		} else {
			setJumpPos(16, RIGHT);
		}
		while (pos >= 0 && joypad() & J_A){
			pos -= 2;
			player[1] -= pos;
			moveWhileJump();
			delay(40);
		}
		while (pos < 12){
			player[1] += pos;
			pos += 2;
			moveWhileJump();
			delay(40);
		}
		player[1] = originalY - 8;
		moverSprite();

		if (flipped){
			crouch(DELAY_CROUCH, LEFT);
		} else {
			crouch(DELAY_CROUCH, RIGHT);
		}
	}
}

void checkDPad(UINT8 jMov, UINT8 mov, int inBounds){
	jump();
	if (joypad() & jMov){
		animateKirby(jMov);
		movLineal(mov, inBounds);
		delay(DELAY_ANIMATION_WALK);
	} else {
		return;
	}
}

void moveLeft(){
	setBounds(-MOVEMENT_WALKING);
	if (scrollDirection == 0)
		scroll_bkg(-MOVEMENT_BACKGROUND, 0);
	checkDPad(J_LEFT, -MOVEMENT_WALKING, inBounds);
}
void moveRight(){
	setBounds(MOVEMENT_WALKING);
	if (scrollDirection == 1)
		scroll_bkg(MOVEMENT_BACKGROUND, 0);
	checkDPad(J_RIGHT, MOVEMENT_WALKING, inBounds);
}
void pause(){
	delay(100);
    set_win_tiles(15, 0, 5, 1, pause_title);
	waitpad(J_START);
    set_win_tiles(15, 0, 5, 1, pause_void);
	delay(100);
}