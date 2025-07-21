#include "enemy.h"
#include "raylib.h"
#include "player.h"
#include <math.h>

extern const unsigned int MAXENEMIES;

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

  enemy.lifetime = 5.0f;

  enemy.active = true;

  return enemy;
}

void drawEnemy(Enemy *enemy){

  DrawRectangle(enemy->x, enemy->y, enemy->width, enemy->height, RED);

}

void updateEnemy(Enemy* enemyArr, Player *player){
      //check the projectile array and update the pos of each projectile
      for(int i = 0; i < MAXENEMIES; i++){

        if(enemyArr[i].active){
          
          enemyMovement(&enemyArr[i], player);

          drawEnemy(&enemyArr[i]);

          enemyArr[i].lifetime -= GetFrameTime();

          if(enemyArr[i].lifetime <= 0){

            enemyArr[i].active = false;

          }

        }
        
      }

}

void initEnemyArr(Enemy* enemyArr){

    //initialize the projectile array
  for (int i = 0; i < MAXENEMIES; i++) {
    enemyArr[i].active = false;
    enemyArr[i].lifetime = 0.0f;
    enemyArr[i].width = 0.0f;
    enemyArr[i].height = 0;
    enemyArr[i].health = 0;
    enemyArr[i].x = 0;
    enemyArr[i].y = 0;
  }


}


