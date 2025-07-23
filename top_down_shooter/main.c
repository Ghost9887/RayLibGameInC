#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "ui.h"
#include "levelSystem.h"
#include "coins.h"
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

void updateGameState(Player *player, Enemy* enemyArr, Projectile* projectileArr, Level *lvl, Coins *coins);

int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  //creating all objects for the game
  Projectile projectileArr[MAXPROJECTILES];
  initProjectileArray(projectileArr);
  Enemy enemyArr[MAXENEMIES];
  initEnemyArr(enemyArr);
  Level lvl = createLevel();
  Coins coins = createCoins();
  Player player = createPlayerObject();

  //creating the first wave of enemies manually
  createEnemies(enemyArr, getAmountOfEnemies(&lvl));

  //MAIN GAME LOOP 
  while(!WindowShouldClose()){

    BeginDrawing();

      ClearBackground(RAYWHITE);

      //UPDATE ALL OF THE GAME STATES
      updateGameState(&player, enemyArr, projectileArr, &lvl, &coins);

    EndDrawing();
  }

  CloseWindow();

  return 0;

}

void updateGameState(Player *player, Enemy* enemyArr, Projectile* projectileArr, Level *lvl, Coins *coins){
    
    updatePlayer(player);

    //checks if the round should end
    updateBreak(lvl, enemyArr);
    
    //drawing
    drawUI(player->health, ENEMYCOUNTER, player->invTime, lvl->level, getCoins(coins));

    //only do these if there are enemies or the round hasn't ended yet
    if(!inBreak(lvl)){
    //check if the enemies are dead
    bool completed = checkIfAllEnemiesAreDestroyed(enemyArr);
    endLevel(completed, lvl, enemyArr);

    //check if the player has anything to shoot at
    //we assign a enemy to a projectiel instead passing the closes enemy
    int enemyIndex = findClosestEnemyToPlayer(enemyArr, player, coins);
    if(enemyIndex != -2){
      if(checkIfPlayerCanShoot(player)){   
        playerShoot(player, projectileArr, enemyArr, coins);
      }
      updateProjectiles(projectileArr, enemyArr, coins); 
    }
      updateEnemy(enemyArr, player);
    }
}

