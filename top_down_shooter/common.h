#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

typedef struct {
  float x;
  float y;
  int width;
  int height;
  int health;
  float cooldown;
  float timer;
  bool canShoot;
  float invTime;
}Player;


typedef struct{
  float x;
  float y;
  int width;
  int height;
  int health;
  int damage;
  bool active;
}Enemy;


typedef struct{
  float x;
  float y;
  int damage;
  int speed;
  bool active;
  float lifetime;
  float size;
}Projectile;

#endif
