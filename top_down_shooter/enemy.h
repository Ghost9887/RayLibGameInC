#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "player.h"

typedef struct{
  int x;
  int y;
  int width;
  int height;
  int health;
}Enemy;

void enemyMovement(Enemy *enemy, Player *player);
void createEnemyObject(Enemy *enemy, int posX, int posY, int width, int height, int health);
void drawEnemy(Enemy *enemy);

#endif
