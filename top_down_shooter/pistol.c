#include "raylib.h"
#include "pistol.h"
#include "player.h"
#include <stdbool.h>

extern const unsigned int TARGETFPS;

Weapon createPistol(){
  Weapon pistol;
  pistol.x = 0;
  pistol.y = 0;
  pistol.width = 20;
  pistol.height = 10;
  pistol.damage = 25;
  pistol.range = 400.0f;
  pistol.fireRate = 0.70f * (float) TARGETFPS; // 1 time per second
  pistol.holding = true;
  return pistol;
}


