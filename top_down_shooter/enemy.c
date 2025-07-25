#include "enemy.h"
#include "raylib.h"
#include "player.h"
#include "coins.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>

extern unsigned int MAXENEMIES;
extern unsigned int ENEMYCOUNTER;
extern const unsigned int SCREENWIDTH;
extern const unsigned int SCREENHEIGHT;
extern const unsigned int MAXSPAWNENEMIES;
extern unsigned int CURRENTSPAWNEDENEMIES;

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

void updateEnemy(Enemy *enemyArr, Player *player){
    for(int i = 0; i < MAXSPAWNENEMIES; i++){
      if(!enemyArr[i].active) continue;
      enemyMovement(&enemyArr[i], player);
      drawEnemy(&enemyArr[i]);
      if (!isPlayerInvulnerable(player) && checkCollisionWithPlayer(&enemyArr[i], player)) {
        playerLoseHealth(&enemyArr[i], player);   
      }
        //draw the enemy health above their heads
        DrawText(TextFormat("%d", (int)enemyArr[i].health),enemyArr[i].x + enemyArr[i].width / 2 - 10, enemyArr[i].y + enemyArr[i].height / 2 - 60, 20, RED);
    }
}

void initEnemyArr(Enemy *enemyArr){
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
int findClosestEnemyToPlayer(Enemy *enemyArr, Player *player, Coins *coins){
  int indexOfEnemy;
  float minDistance = 100000.0f;
  for(int i = 0; i < MAXSPAWNENEMIES; i++){
    if(!enemyArr[i].active) continue;
    float temp = minDistance;
    checkHealth(&enemyArr[i], coins);
    minDistance = fabs(fmin(calculateDistance(&enemyArr[i], player), minDistance));
    if(temp != minDistance){
      indexOfEnemy = i;
    }
  } 
  //checks if the player can shoot or not
  Weapon weapon = player->weapon;
  if(minDistance < weapon.range){
  return indexOfEnemy;
  }
  return -2;
}

float calculateDistance(Enemy *enemy, Player *player){
  float dx = player->x - enemy->x;
  float dy = player->y - enemy->y;
  return sqrtf(dx * dx + dy * dy);
}

void checkHealth(Enemy *enemy, Coins *coins){
  if(enemy->health <= 0) destroyEnemy(enemy, coins);
}

void destroyEnemy(Enemy *enemy, Coins *coins){
  enemy->active = false;
  ENEMYCOUNTER--;
  CURRENTSPAWNEDENEMIES--;
  addCoins(50, coins);
}

bool checkCollisionWithPlayer(Enemy *enemy, Player *player){
  //create the enemy rectangle from its data
    Rectangle enemyRect = { enemy->x, enemy->y, enemy->width, enemy->height };
    Rectangle playerRect = {player->x, player->y, player->width, player->height};
    return CheckCollisionRecs(enemyRect, playerRect);
}

//spawns the enemies
void createEnemies(Enemy *enemyArr, int enemyCount){
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    //if there are less enemies we dont have to check if there is a available slot
    if(enemyCount <= MAXSPAWNENEMIES){
      for (int i = 0; i < enemyCount; i++) {
          float randomX = SCREENWIDTH / 2 + rand() % SCREENWIDTH;
          float randomY = SCREENHEIGHT / 2 + rand() % SCREENHEIGHT;
          enemyArr[i] = createEnemyObject(randomX, randomY);
          CURRENTSPAWNEDENEMIES++;
      }
    }else{
      for(int i = 0; i < MAXSPAWNENEMIES; i++){
        if(!enemyArr[i].active){
          float randomX = rand() % SCREENWIDTH * 2;
          float randomY = rand() % SCREENHEIGHT * 2;
          enemyArr[i] = createEnemyObject(randomX, randomY);
          CURRENTSPAWNEDENEMIES++;
        }
      }
    }
}

bool checkIfAllEnemiesAreDestroyed(Enemy *enemy){
  if(ENEMYCOUNTER == 0){
    return true;
  }
  return false;
}

void enemyLoseHealth(float damage, Enemy *enemy){
  enemy->health -= damage;
}






