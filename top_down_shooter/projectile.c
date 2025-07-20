#include "raylib.h"
#include "projectile.h"

extern const unsigned int MAXPROJECTILES;

Projectile createProjectile(int posX, int posY){

  Projectile projectile;

  projectile.x = posX;

  projectile.y = posY;

  projectile.damage = 100;

  projectile.speed = 10;

  projectile.active = true;

  projectile.lifetime = 2.0f;

  return projectile;

}

void drawProjectile(Projectile *projectile){

  DrawCircle(projectile->x, projectile->y, 20, GREEN);
 
}

void moveProjectile(Projectile *projectile, Enemy *enemy){
  
  if(projectile->x < enemy->x) projectile->x += projectile->speed;
  if(projectile->x > enemy->x) projectile->x -= projectile->speed;
  if(projectile->y < enemy->y) projectile->y += projectile->speed;
  if(projectile->y > enemy->y) projectile->y -= projectile->speed;

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


