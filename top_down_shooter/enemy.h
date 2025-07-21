#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "common.h"

void enemyMovement(Enemy *enemy, Player *player);
Enemy createEnemyObject(float posX, float posY);
void drawEnemy(Enemy *enemy);

#endif
