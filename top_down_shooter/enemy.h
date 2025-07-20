#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "common.h"

void enemyMovement(Enemy *enemy, Player *player);
void createEnemyObject(Enemy *enemy, int posX, int posY, int width, int height, int health);
void drawEnemy(Enemy *enemy);

#endif
