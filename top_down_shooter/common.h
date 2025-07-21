#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

typedef struct {
  float x;
  float y;
  int width;
  int height;
  int health;
  int ammo;
  float cooldown;
  float timer;
  bool canShoot;
}Player;


typedef struct{
  float x;
  float y;
  int width;
  int height;
  int health;
  bool active;
  float lifetime;
}Enemy;


typedef struct{
  float x;
  float y;
  int damage;
  int speed;
  bool active;
  float lifetime;
}Projectile;


#endif
