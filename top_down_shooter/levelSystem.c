#include "raylib.h"
#include "enemy.h"
#include "ui.h"
#include "levelSystem.h"

extern unsigned int ENEMYCOUNTER;

Level createLevel(){
  Level lvl;
  lvl.level = 0;
  lvl.breakTimer = 0.0f;
  lvl.inBreak = false;
  return lvl;
}

int getLevel(Level *lvl){
  return lvl->level;
}

bool inBreak(Level *lvl){
  return lvl->inBreak;
}

void reduceBreakTimer(Level *lvl){
  lvl->breakTimer -= GetFrameTime();
}

float getBreakTimer(Level *lvl){
  return lvl->breakTimer;
}

int getAmountOfEnemies(Level *lvl){
  return 6 * getLevel(lvl);
}

void changeBreak(bool value, Level *lvl){
  lvl->inBreak = value;
}

void startLevel(Level *lvl, Enemy* enemyArr){
  lvl->level = getLevel(lvl) + 1; 
  changeBreak(false, lvl);
  ENEMYCOUNTER = getAmountOfEnemies(lvl);
  //spawns the enemies at the start of the round
  createEnemies(enemyArr, getAmountOfEnemies(lvl));
}

void endLevel(bool completed, Level *lvl, Enemy* enemyArr){
  if(completed){
    lvl->inBreak = true;
    lvl->breakTimer = 2.0f;
  }
}

void updateBreak(Level *lvl, Enemy* enemyArr){
  if(inBreak(lvl)){
    reduceBreakTimer(lvl);
    showBreakUI(getBreakTimer(lvl));
    if(getBreakTimer(lvl) <= 0){
      startLevel(lvl, enemyArr);
    }
  }
}


