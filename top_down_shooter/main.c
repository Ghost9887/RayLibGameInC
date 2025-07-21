#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "ui.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//GLOBAL VARIABLES
const unsigned int SCREENWIDTH = 1200;
const unsigned int SCREENHEIGHT = 800; 
const unsigned int TARGETFPS = 60;
const unsigned int MAXENEMIES = 100;
const unsigned int MAXPROJECTILES = 200;
unsigned int ENEMYCOUNTER = 0;

int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  Projectile projectileArr[MAXPROJECTILES];

  initProjectileArray(projectileArr);

  Enemy enemyArr[MAXENEMIES];

  initEnemyArr(enemyArr);
  
  //create the player
  Player player = createPlayerObject();

  
  while(!WindowShouldClose()){

      //call player movement
    playerMovement(&player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      drawUI(player.health, ENEMYCOUNTER, player.invTime);

      
      //keeps track of the invincibility timer
      invTimer(&player);

      drawPlayer(&player);
      
      checkIfPlayerCanShoot(&player);

      if(player.canShoot){   
        playerShoot(&player, projectileArr);
          
        //TEST CREATING ENEMIES
           int indexToReplace;
        for(indexToReplace = 0; indexToReplace < MAXENEMIES; indexToReplace++){
            if(!enemyArr[indexToReplace].active){
              break;
            }
        }
        srand(time(0));
        float randomX = rand() % SCREENWIDTH;
        float randomY = rand() % SCREENHEIGHT;
        enemyArr[indexToReplace] = createEnemyObject(randomX, randomY);
        ENEMYCOUNTER++;
      }

      updateProjectiles(projectileArr, findClosestEnemyToPlayer(enemyArr, &player)); 

      updateEnemy(enemyArr, &player);

    EndDrawing();
  }

  CloseWindow();

  return 0;

}


