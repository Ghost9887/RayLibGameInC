#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "ui.h"
#include "levelSystem.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//GLOBAL VARIABLES
const unsigned int SCREENWIDTH = 1200;
const unsigned int SCREENHEIGHT = 800; 
const unsigned int TARGETFPS = 60;
const unsigned int MAXPROJECTILES = 200;
const unsigned int MAXENEMIES = 200;
unsigned int ENEMYCOUNTER = 0;

int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  Projectile projectileArr[MAXPROJECTILES];

  initProjectileArray(projectileArr);

  Enemy enemyArr[MAXENEMIES];

  initEnemyArr(enemyArr);
  
  Level lvl = createLevel();

  createEnemies(enemyArr, getAmountOfEnemies(&lvl));
  //create the player
  Player player = createPlayerObject();

  
  while(!WindowShouldClose()){

      //call player movement
    playerMovement(&player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      drawUI(player.health, ENEMYCOUNTER, player.invTime, lvl.level);

      //REFACTOR INTO FUNCTIONS    
      if(lvl.inBreak){
      lvl.breakTimer -= GetFrameTime();
      showBreakUI(lvl.breakTimer);
      if(lvl.breakTimer <= 0){
        lvl.inBreak = false;
        startLevel(&lvl, enemyArr);
      }
      }

      //keeps track of the invincibility timer
      invTimer(&player);

      drawPlayer(&player);
      
      checkIfPlayerCanShoot(&player);


      //REFACTOR INTO FUNCTIONS
      if(!lvl.inBreak){
        //check if the enemies are dead
        bool completed = checkIfAllEnemiesAreDestroyed(enemyArr);
        endLevel(completed, &lvl, enemyArr);
        
        Enemy *enemy = findClosestEnemyToPlayer(enemyArr, &player);
        if(enemy != NULL){
        if(player.canShoot){   
          playerShoot(&player, projectileArr);
        }
        updateProjectiles(projectileArr, enemy); 
      }
        updateEnemy(enemyArr, &player);
      }

    EndDrawing();
  }

  CloseWindow();

  return 0;

}


