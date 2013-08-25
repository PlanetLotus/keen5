// Header file for Player class

//#include "Unit.h"

#ifndef PLAYER_H
#define PLAYER_H

enum directionEnum {UP, DOWN, LEFT, RIGHT};

class Player {
    private:
        int ammo;
        int xspeed;     // Movement speed
        int yspeed;     // Movement speed

        int frameWidth;
        int frameHeight;
        int frame;
        int state;      // Which animation state
    public:
        Player();
        void shoot();
        void walk(directionEnum dir);
        void jump();
        void pogo();
        void look(directionEnum dir);
        void climb(directionEnum dir);
        void enter_door();
        void draw();

        // Getters and setters
        void set_ammo(int x);
        void set_xspeed(int x);
        void set_yspeed(int y);
        void set_state(int x);

        int get_ammo();
        int get_xspeed();
        int get_yspeed();
        int get_state();

        int get_frameWidth();
        int get_frameHeight();
};

#endif
