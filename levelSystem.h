#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include "raylib.h"
#include "common.h"


int getLevel(Level *lvl);
int getAmountOfEnemies(Level *lvl);
void startLevel(Level *lvl, Enemy* enemyArr);
Level createLevel();
void endLevel(bool completed, Level *lvl, Enemy* enemyArr);


#endif
