#include "raylib.h"
#include "ui.h"

extern const unsigned int SCREENWIDTH;
extern const unsigned int SCRRENHEIGHT;

void drawUI(int health, int ammo, int projectileCount, int maxProjectiles){
  
  DrawText(TextFormat("Health: %d", health), 25, 25, 40, BLACK);
  
  DrawText(TextFormat("Ammo: %d", ammo), 25, 80, 40, BLACK);

  DrawText(TextFormat("Projectile count: %d", projectileCount), 25, 135, 40, BLACK);

  DrawText(TextFormat("Max projectiles: %d", maxProjectiles), 25, 185, 40, BLACK);

}


