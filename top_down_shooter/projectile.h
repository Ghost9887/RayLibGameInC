#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "common.h"

Projectile createProjectile(int indexOfEnemy, Player *player, Weapon *weapon);
void drawProjectile(Projectile *projectile);
void moveProjectile(Projectile *projectile, Enemy *enemy);
void updateProjectiles(Projectile *projectileArr, Enemy* enemyArr, Coins *coins);
void destroyProjectile(Projectile *projectile);
void initProjectileArray(Projectile *projectileArr);
bool checkForCollisionWithEnemy(Projectile *projectile, Enemy *enemy, Coins *coins);
void explosiveProjectile(Projectile *projectile, Enemy *enemy, Enemy *enemyArr);

#endif
