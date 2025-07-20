#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "projectile.h"
#include <stdbool.h>

typedef struct {
  int x;
  int y;
  int width;
  int height;
  int health;
  int ammo;
  float cooldown;
  float timer;
  bool canShoot;
}Player;

void createPlayerObject(Player *player);
void drawPlayer(Player *player);
void playerMovement(Player *player);
void checkIfPlayerCanShoot(Player *player);
void playerShoot(Player *player, Projectile* projectileArr);


#endif
