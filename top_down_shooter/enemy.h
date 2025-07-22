#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "common.h"
#include <stdbool.h>

void enemyMovement(Enemy *enemy, Player *player);
Enemy createEnemyObject(float posX, float posY);
void drawEnemy(Enemy *enemy);
void updateEnemy(Enemy* enemyArr, Player *player);
void initEnemyArr(Enemy* enemyArr);
Enemy *findClosestEnemyToPlayer(Enemy* enemyArr, Player *player); 
float calculateDistance(Enemy *enemy, Player *player);
void destroyEnemy(Enemy *enemy);
void checkHealth(Enemy *enemy);
bool checkCollisionWithPlayer(Enemy *enemy, Player *player);
void createEnemies(Enemy* enemArr, int enemyCount);
bool checkIfAllEnemiesAreDestroyed(Enemy* enemy);

#endif
