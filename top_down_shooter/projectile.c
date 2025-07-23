#include "raylib.h"
#include "projectile.h"
#include "coins.h"
#include "enemy.h"
#include <math.h>
#include <stdio.h>

extern int MAXPROJECTILES;

Projectile createProjectile(int indexOfEnemy, Player *player, Coins *coins){
  Projectile projectile;
  projectile.x = player->x;
  projectile.y = player->y;
  projectile.damage = 100;
  projectile.target = indexOfEnemy; 
  projectile.speed = 30;
  projectile.active = true;
  projectile.lifetime = 10.0f;
  projectile.size = 5.0f;
  return projectile;
}

void drawProjectile(Projectile *projectile){
  DrawCircle(projectile->x, projectile->y, projectile->size, BLACK);
}

void moveProjectile(Projectile *projectile, Enemy *enemy) {
    float dx = (enemy->x + enemy->width / 2) - projectile->x;
    float dy = (enemy->y + enemy->height / 2) - projectile->y;
    float length = sqrt(dx * dx + dy * dy);
    float dirX = dx / length;
    float dirY = dy / length;
    projectile->x += dirX * projectile->speed;
    projectile->y += dirY * projectile->speed;
}


void updateProjectiles(Projectile* projectileArr, Enemy* enemyArr, Coins *coins){
      for(int i = 0; i < MAXPROJECTILES; i++){
       if(projectileArr[i].active){
          if(checkForCollisionWithEnemy(&projectileArr[i], &enemyArr[projectileArr[i].target], coins)){ 
            destroyProjectile(&projectileArr[i]);
            addCoins(20, coins);
            enemyLoseHealth(50, &enemyArr[projectileArr[i].target]);
          }
          moveProjectile(&projectileArr[i], &enemyArr[projectileArr[i].target]);
          drawProjectile(&projectileArr[i]);
          projectileArr[i].lifetime -= GetFrameTime();
          if(projectileArr[i].lifetime <= 0){
            projectileArr[i].active = false;
          }
        }
      }
}

void destroyProjectile(Projectile *projectile){
  projectile->active = false;
}

void initProjectileArray(Projectile* projectileArr){
  //initialize the projectile array
  for (int i = 0; i < MAXPROJECTILES; i++) {
    projectileArr[i].active = false;
    projectileArr[i].lifetime = 0.0f;
    projectileArr[i].speed = 0.0f;
    projectileArr[i].damage = 0;
    projectileArr[i].x = 0;
    projectileArr[i].y = 0;
  }
}

bool checkForCollisionWithEnemy(Projectile *projectile, Enemy *enemy, Coins *coins){
    //create the enemy rectangle from its data
    Rectangle enemyRect = { enemy->x, enemy->y, enemy->width, enemy->height };
    return CheckCollisionCircleRec(
        (Vector2){ projectile->x, projectile->y }, projectile->size, enemyRect
    );
}



