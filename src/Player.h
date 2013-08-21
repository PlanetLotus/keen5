// Header file for Player class

#ifndef PLAYER_H
#define PLAYER_H

enum directionEnum {UP, DOWN, LEFT, RIGHT}

class Player {
    private:
        int ammo;
        int xspeed;      // Movement speed
        int yspeed;      // Movement speed
        int state;      // Which animation state
    public:
        void shoot();
        void walk(directionEnum dir);
        void jump();
        void pogo();
        void look(directionEnum dir);
        void climb(directionEnum dir);
        void enter_door();
}

#endif
