#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

typedef struct {
  int x;
  int y;
  int width;
  int height;
  int health;
  int ammo;
  float cooldown;
  float timer;
  bool canShoot;
}Player;


typedef struct{
  int x;
  int y;
  int width;
  int height;
  int health;
}Enemy;


typedef struct{
  int x;
  int y;
  int damage;
  int speed;
  bool active;
  float lifetime;
}Projectile;


#endif
