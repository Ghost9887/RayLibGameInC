#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"

typedef struct{
  int x;
  int y;
  int damage;
  int speed;
  bool active;
  float lifetime;
}Projectile;

Projectile createProjectile(int posX, int posY);
void drawProjectile(Projectile *projectile);
void moveProjectile(Projectile *projectile);
void updateProjectiles(Projectile* projectileArr);

#endif
