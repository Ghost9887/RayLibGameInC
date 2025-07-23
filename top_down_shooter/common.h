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
  float range;
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
  int target;
  bool active;
  float lifetime;
  float size;
}Projectile;

typedef struct{
  int level;
  bool inBreak;
  float breakTimer;
}Level;

typedef struct{
  int coinCounter;
}Coins;

#endif
