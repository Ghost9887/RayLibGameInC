#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "common.h"

Projectile createProjectile(float posX, float posY);
void drawProjectile(Projectile *projectile);
void moveProjectile(Projectile *projectile, Enemy *enemy);
void updateProjectiles(Projectile* projectileArr, Enemy *enemy);
void destroyProjectile(Projectile *projectile);

#endif
