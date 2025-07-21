#include "enemy.h"
#include "raylib.h"
#include "player.h"
#include <math.h>

extern const unsigned int MAXENEMIES;
extern unsigned int ENEMYCOUNTER;

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
  enemy.damage = 10;
  enemy.active = true;
  return enemy;
}

void drawEnemy(Enemy *enemy){
  DrawRectangle(enemy->x, enemy->y, enemy->width, enemy->height, RED);
}

void updateEnemy(Enemy* enemyArr, Player *player){
      for(int i = 0; i < MAXENEMIES; i++){
        if(enemyArr[i].active){
          enemyMovement(&enemyArr[i], player);
          drawEnemy(&enemyArr[i]);
        if (!isPlayerInvulnerable(player) && checkCollisionWithPlayer(&enemyArr[i], player)) {
          playerLoseHealth(&enemyArr[i], player);   
        }

        }
      }
}

void initEnemyArr(Enemy* enemyArr){
    //initialize the projectile array
  for (int i = 0; i < MAXENEMIES; i++) {
    enemyArr[i].active = false;
    enemyArr[i].width = 0.0f;
    enemyArr[i].height = 0;
    enemyArr[i].health = 0;
    enemyArr[i].x = 0;
    enemyArr[i].y = 0;
  }
}

//MAYBE MOVE TO PLAYER FILE ???
Enemy *findClosestEnemyToPlayer(Enemy* enemyArr, Player *player){
  int indexOfEnemy;
  float minDistance = 100000.0f;
  for(int i = 0; i < MAXENEMIES; i++){
    float temp = minDistance;
    if(enemyArr[i].active){
      checkHealth(&enemyArr[i]);
      minDistance = fabs(fmin(calculateDistance(&enemyArr[i], player), minDistance));
    }
    if(temp != minDistance){
      indexOfEnemy = i;
    }
  } 
  return &enemyArr[indexOfEnemy];
}

float calculateDistance(Enemy *enemy, Player *player){
  float dx = player->x - enemy->x;
  float dy = player->y - enemy->y;
  return sqrtf(dx * dx + dy * dy);
}

void checkHealth(Enemy *enemy){
  if(enemy->health <= 0) destroyEnemy(enemy);
}

void destroyEnemy(Enemy *enemy){
  enemy->active = false;
  ENEMYCOUNTER--;
}

bool checkCollisionWithPlayer(Enemy *enemy, Player *player){
  //create the enemy rectangle from its data
    Rectangle enemyRect = { enemy->x, enemy->y, enemy->width, enemy->height };
    Rectangle playerRect = {player->x, player->y, player->width, player->height};
    return CheckCollisionRecs(enemyRect, playerRect);
 
}


