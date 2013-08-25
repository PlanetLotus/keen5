// Player definition

#include "helpers.h"
#include "Player.h"

Player::Player() {
    ammo = 5;   // Might depend on difficulty level
    xspeed = 10;
    yspeed = 7;

    frameWidth = 64;
    frameHeight = 80;
    frame = 0;
    state = 0;
}

void Player::shoot() {
    return;
}

void Player::walk(directionEnum dir) {
    return;
}

void Player::jump() {
    return;
}

void Player::pogo() {
    return;
}

void Player::look(directionEnum dir) {
    return;
}

void Player::climb(directionEnum dir) {
    return;
}

void Player::enter_door() {
    return;
}

void Player::draw() {
    // Go to next frame
    frame++;
    if (frame >= 5)
        frame = 0;

    SDL_Rect tempRect;
    tempRect.x = frame * frameWidth;
    tempRect.y = 0;
    tempRect.w = frameWidth;
    tempRect.h = frameHeight;

    // Draw the character
    apply_surface(50, 50, keen, screen, &tempRect);
}

// Getters and setters

void Player::set_ammo(int x) { ammo = x; }
void Player::set_xspeed(int x) { xspeed = x; }
void Player::set_yspeed(int y) { xspeed = y; }
void Player::set_state(int x) { state = x; }

int Player::get_ammo() { return ammo; }
int Player::get_xspeed() { return xspeed; }
int Player::get_yspeed() { return yspeed; }
int Player::get_state() { return state; }

int Player::get_frameWidth() { return frameWidth; }
int Player::get_frameHeight() { return frameHeight; }
