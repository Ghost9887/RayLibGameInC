#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"
#include "raylib.h"
#include <stdbool.h>

void createPlayerObject(Player *player);
void drawPlayer(Player *player);
void playerMovement(Player *player);
void checkIfPlayerCanShoot(Player *player);
void playerShoot(Player *player, Projectile* projectileArr);


#endif
