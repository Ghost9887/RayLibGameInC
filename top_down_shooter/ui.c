#include "raylib.h"
#include "ui.h"
#include "player.h"

extern const unsigned int SCREENWIDTH;
extern const unsigned int SCRRENHEIGHT;

void drawUI(int health, int enemyCounter, float invTimer){
  
  DrawText(TextFormat("Health: %d", health), 25, 25, 40, BLACK);
  
  DrawText(TextFormat("Vulnerable: %f", invTimer), 25, 135, 40, BLACK);
  DrawText(TextFormat("Enemy count: %d", enemyCounter), 25, 80, 40, BLACK);
  

}


