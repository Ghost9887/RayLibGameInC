#include "raylib.h"
#include "enemy.h"
#include "ui.h"
#include "levelSystem.h"

Level createLevel(){
  Level lvl;
  lvl.level = 1;
  lvl.breakTimer = 0.0f;
  lvl.inBreak = false;
  return lvl;
}

int getLevel(Level *lvl){
  return lvl->level;
}

int getAmountOfEnemies(Level *lvl){
  return 6 * getLevel(lvl);
}

void startLevel(Level *lvl, Enemy* enemyArr){
  lvl->level = getLevel(lvl) + 1; 
  getAmountOfEnemies(lvl);
  createEnemies(enemyArr, getAmountOfEnemies(lvl));
}

void endLevel(bool completed, Level *lvl, Enemy* enemyArr){
  if(completed){
    lvl->inBreak = true;
    lvl->breakTimer = 20.0f;
  }
}


