#include "enemy.h"
#include "raylib.h"
#include "player.h"

void enemyMovement(Enemy *enemy, Player *player){
  
  float movementSpeed = 2.0f;
  
  if(enemy->x > player->x){
    enemy->x -= movementSpeed;
  }   
  if(enemy->y > player->y){
    enemy->y -= movementSpeed;
  }
  if(enemy->x < player->x){
    enemy->x += movementSpeed;
  }
  if(enemy->y < player->y){
    enemy->y += movementSpeed;
  }
  
}

void createEnemyObject(Enemy *enemy, int posX, int posY, int width, int height, int health){
  
  enemy->x = posX;
  
  enemy->y = posY;

  enemy->width = width;

  enemy->height = height;

  enemy->health = health;
}

void drawEnemy(Enemy *enemy){

  DrawRectangle(enemy->x, enemy->y, enemy->width, enemy->height, RED);

}


