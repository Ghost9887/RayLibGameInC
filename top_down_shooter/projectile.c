#include "raylib.h"
#include "projectile.h"
#include <math.h>

extern const unsigned int MAXPROJECTILES;

Projectile createProjectile(int posX, int posY){

  Projectile projectile;

  projectile.x = posX;

  projectile.y = posY;

  projectile.damage = 100;

  projectile.speed = 4;

  projectile.active = true;

  projectile.lifetime = 5.0f;

  return projectile;

}

void drawProjectile(Projectile *projectile){

  DrawCircle(projectile->x, projectile->y, 20, GREEN);
 
}

void moveProjectile(Projectile *projectile, Enemy *enemy) {
    // Calculate direction vector to enemy
    float dx = enemy->x - projectile->x;
    float dy = enemy->y - projectile->y;

    // Calculate the length of the vector
    float length = sqrt(dx * dx + dy * dy);
    if (length < 0.0001f ) return; // Already at target

    // Normalize direction vector
    float dirX = dx / length;
    float dirY = dy / length;

    // Move projectile along direction
    projectile->x += dirX * projectile->speed;
    projectile->y += dirY * projectile->speed;
}



void updateProjectiles(Projectile* projectileArr, Enemy *enemy){

      //check the projectile array and update the pos of each projectile
      for(int i = 0; i < MAXPROJECTILES; i++){

        if(projectileArr[i].active){

          moveProjectile(&projectileArr[i], enemy);

          drawProjectile(&projectileArr[i]);

          projectileArr[i].lifetime -= GetFrameTime();

          if(projectileArr[i].lifetime <= 0){

            projectileArr[i].active = false;

          }

        }
        
      }

}


