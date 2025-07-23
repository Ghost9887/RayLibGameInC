#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "ui.h"
#include "roundSystem.h"
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
const unsigned int MAXENEMIES = 500;
const unsigned int MAXSPAWNENEMIES = 40;
unsigned int ENEMYCOUNTER = 0;
unsigned int CURRENTSPAWNEDENEMIES = 0;

void updateGameState(Player *player, Enemy *enemyArr, Projectile *projectileArr, Round *rnd, Coins *coins);

int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  //creating all objects for the game
  Projectile projectileArr[MAXPROJECTILES];
  initProjectileArray(projectileArr);
  Enemy enemyArr[MAXENEMIES];
  initEnemyArr(enemyArr);
  Round rnd = createRoundObject();
  Coins coins = createCoins();
  Player player = createPlayerObject();
  
  //start the first round
  startRound(&rnd, enemyArr);

  //MAIN GAME LOOP 
  while(!WindowShouldClose()){

    BeginDrawing();

      ClearBackground(RAYWHITE);

      //UPDATE ALL OF THE GAME STATES
      updateGameState(&player, enemyArr, projectileArr, &rnd, &coins);

    EndDrawing();
  }

  CloseWindow();

  return 0;

}

void updateGameState(Player *player, Enemy *enemyArr, Projectile *projectileArr, Round *rnd, Coins *coins){
    
    updatePlayer(player);

    //checks if the round should end
    updateBreak(rnd, enemyArr);
    
    //drawing
    drawUI(player->health, ENEMYCOUNTER, player->invTime, rnd->round, getCoins(coins), CURRENTSPAWNEDENEMIES);

    //only do these if there are enemies or the round hasn't ended yet
    if(!inBreak(rnd)){
      //check if the player has anything to shoot at if so create the projectile with the target of the indexOfEnemy
      int indexOfEnemy = findClosestEnemyToPlayer(enemyArr, player, coins);
      //only call this if there are more enemies that need to be spawned druring the round
      if(MAXSPAWNENEMIES <= ENEMYCOUNTER){
        createEnemies(enemyArr, getAmountOfEnemies(rnd));
      }
      //check if the closes enemy is in range of shooting
      if(indexOfEnemy != -2 && checkIfPlayerCanShoot(player)){
        playerShoot(player, projectileArr, indexOfEnemy, coins);
      }
      updateProjectiles(projectileArr, enemyArr, coins); 
    }
    updateEnemy(enemyArr, player);
}

