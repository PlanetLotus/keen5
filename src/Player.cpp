// Player definition

#include "Player.h"

Player::Player() {
    ammo = 5;   // Might depend on difficulty level
    xspeed = 10;
    yspeed = 7;
    state = 0;
}

void Player::shoot() {
    NULL;
}

void Player::walk(directionEnum dir) {
    NULL;
}

void Player::jump() {
    NULL;
}

void Player::pogo() {
    NULL;
}

void Player::look(directionEnum dir) {
    NULL;
}

void Player::climb(directionEnum dir) {
    NULL;
}

void Player::enter_door() {
    NULL;
}

// Getters and setters

void Player::set_ammo(int x) { ammo = x; }
void Player::set_xspeed(int x) { xspeed = x; }
void Player::set_yspeed(int y) { xspeed = y; }
void Player::set_state(int x) { state = x; }

int Player::get_ammo() { return ammo; }
int Player::get_xspeed() { return xspeed; }
int Player::get_yspeed() { return yspeed; }
int Player::get_status() { return status; }
