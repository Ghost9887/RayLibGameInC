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
const unsigned int MAXENEMIES = 100;


int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  Projectile projectileArr[MAXPROJECTILES];

  initProjectileArray(projectileArr);

  Enemy enemyArr[MAXENEMIES];

  initEnemyArr(enemyArr);
  
  //create the player
  Player player = createPlayerObject();

  //create a enemy
  enemyArr[0] = createEnemyObject(200.0f, 200.0f);
  enemyArr[1] = createEnemyObject(100.0f, 100.0f);

  while(!WindowShouldClose()){

    //call player movement
    playerMovement(&player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      drawUI(player.health, player.ammo, PROJECTILECOUNT, MAXPROJECTILES);

      drawPlayer(&player);
      
      checkIfPlayerCanShoot(&player);

      if(player.canShoot){   
        playerShoot(&player, projectileArr);
      }

      updateProjectiles(projectileArr, &enemyArr[0]); 

      updateEnemy(enemyArr, &player);

    EndDrawing();
  }

  CloseWindow();

  return 0;

}


