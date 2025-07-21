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
int MAXPROJECTILES = 100;
int PROJECTILECOUNT = 0;


int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  Projectile projectileArr[MAXPROJECTILES];
  
  initArray(projectileArr);

  //create the player
  Player player = createPlayerObject();

  //create a enemy
  Enemy enemy1 = createEnemyObject(200.0f, 200.0f);
  Enemy enemy2 = createEnemyObject(100.0f, 100.0f);

  while(!WindowShouldClose()){

    //call player movement
    playerMovement(&player);

    enemyMovement(&enemy1, &player);

    enemyMovement(&enemy2, &player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      drawUI(player.health, player.ammo, PROJECTILECOUNT, MAXPROJECTILES);

      drawPlayer(&player);
      drawEnemy(&enemy1);
      drawEnemy(&enemy2);
      
      checkIfPlayerCanShoot(&player);

      if(player.canShoot){   
        playerShoot(&player, projectileArr);
      }

      updateProjectiles(projectileArr, &enemy1); 

    EndDrawing();
  }

  CloseWindow();

  return 0;

}


