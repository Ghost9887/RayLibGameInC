#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "ui.h"
#include <stdio.h>
#include <stdbool.h>

//GLOBAL VARIABLES
const unsigned int SCREENWIDTH = 1200;
const unsigned int SCREENHEIGHT = 800; 
const unsigned int TARGETFPS = 60;
const unsigned int MAXPROJECTILES = 200;


int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  Projectile projectileArr[MAXPROJECTILES];

  //create the player
  Player player;
  createPlayerObject(&player);

  //create a enemy
  Enemy enemy1;
  createEnemyObject(&enemy1, 200.0f, 200.0f, 30, 50, 100);

  Enemy enemy2;
  createEnemyObject(&enemy2, 100.0f, 100.0f, 30, 50, 100);

  while(!WindowShouldClose()){

    //call player movement
    playerMovement(&player);

    enemyMovement(&enemy1, &player);

    enemyMovement(&enemy2, &player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      drawUI(player.health, player.ammo);

      drawPlayer(&player);
      
      checkIfPlayerCanShoot(&player);

      if(player.canShoot){   
        playerShoot(&player, projectileArr);
      }

      updateProjectiles(projectileArr, &enemy1); 

      drawEnemy(&enemy1);
      drawEnemy(&enemy2);


    EndDrawing();
  }

  CloseWindow();

  return 0;

}


