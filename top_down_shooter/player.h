#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"
#include "raylib.h"
#include <stdbool.h>

Player createPlayerObject();
void drawPlayer(Player *player);
void playerMovement(Player *player);
bool checkIfPlayerCanShoot(Player *player);
void playerShoot(Player *player, Projectile* projectileArr, Enemy* enemyArr, Coins* coins);
void playerLoseHealth(Enemy *enemy, Player *player);
bool isPlayerInvulnerable(Player *player);
void invTimer(Player *player);
void updatePlayer(Player *player);

#endif
