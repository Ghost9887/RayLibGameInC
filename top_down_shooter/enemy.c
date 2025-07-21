#include "enemy.h"
#include "raylib.h"
#include "player.h"
#include <math.h>

void enemyMovement(Enemy *enemy, Player *player){
    const float movementSpeed = 1.5f;

    float dx = player->x - enemy->x;
    float dy = player->y - enemy->y;

    float length = sqrtf(dx * dx + dy * dy);
    if (length < 0.1f) return;

    float dirX = dx / length;
    float dirY = dy / length;

    enemy->x += dirX * movementSpeed;
    enemy->y += dirY * movementSpeed;
}

Enemy createEnemyObject(float posX, float posY){
  Enemy enemy;

  enemy.x = posX;
  
  enemy.y = posY;

  enemy.width = 30;

  enemy.height = 50;

  enemy.health = 100;

  return enemy;
}

void drawEnemy(Enemy *enemy){

  DrawRectangle(enemy->x, enemy->y, enemy->width, enemy->height, RED);

}


