#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "common.h"

Projectile createProjectile(int posX, int posY);
void drawProjectile(Projectile *projectile);
void moveProjectile(Projectile *projectile, Enemy *enemy);
void updateProjectiles(Projectile* projectileArr, Enemy *enemy);

#endif
