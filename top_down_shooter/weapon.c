#include "raylib.h"
#include "weapon.h"
#include "player.h"
#include "pistol.h"
#include "assaultRifle.h"

void drawWeapon(Player *player, Weapon *weapon){ 
  DrawRectangle(player->x, player->y, weapon->width, weapon->height, BLACK);
}

void initWeaponArr(Weapon *weaponArr){
  weaponArr[0] = createPistol();
  weaponArr[1] = createAssaultRifle();
  for(int i = 2; i < 10; i++){
    weaponArr[i] = createPistol();
  }
}

void switchWeapons(Player *player, Weapon *weaponArr){
  if(IsKeyPressed(KEY_ONE)){
    weaponArr[0].holding = true;
    weaponArr[1].holding = false;
  }
  else if(IsKeyPressed(KEY_TWO)){
    weaponArr[1].holding = true;
    weaponArr[0].holding = false;
  }
}
