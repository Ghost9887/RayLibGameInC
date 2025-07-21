#include "player.h"
#include "projectile.h"
#include "raylib.h"

extern const unsigned int SCREENWIDTH;
extern const unsigned int SCREENHEIGHT;
extern const unsigned int TARGETFPS;
extern const unsigned int MAXPROJECTILES;

void createPlayerObject(Player *player){
  player->x = (float) SCREENWIDTH / (float) 2;
  player->y = (float) SCREENHEIGHT / (float) 2;
  player->width = 30;
  player->height = 50;
  player->health = 100;
  player->ammo = 2000;
  player->cooldown = 0.5f;
  player->timer = player->cooldown * (float) TARGETFPS;
  player->canShoot = true;
}

void drawPlayer(Player *player){
  DrawRectangle(player->x, player->y, player->width, player->height, BLUE);
}

void playerMovement(Player *player){
  float movementSpeed = 5.0f;
  if(IsKeyDown(KEY_A) && player->x > 0) player->x -= movementSpeed;
  if(IsKeyDown(KEY_D) && player->x + player->width < SCREENWIDTH) player->x += movementSpeed;
  if(IsKeyDown(KEY_S) && player->y + player->height < SCREENHEIGHT) player->y += movementSpeed;
  if(IsKeyDown(KEY_W) && player->y > 0) player->y -= movementSpeed;
}

void playerShoot(Player *player, Projectile* projectileArr){
  
  //find a inactive projectile and replace it

  int indexToReplace;

  for(indexToReplace = 0; indexToReplace < MAXPROJECTILES; indexToReplace++){

    if(!projectileArr[indexToReplace].active){

      break;

    }

  }

  if(player->canShoot){

    player->canShoot = false;

    player->timer = player->cooldown * (float) TARGETFPS;

    projectileArr[indexToReplace] = createProjectile(player->x, player->y); 

  }

}

void checkIfPlayerCanShoot(Player *player) {
    if (!player->canShoot && player->timer > 0) {
        player->timer--;
    }
    if (player->timer <= 0) {
        player->canShoot = true;
    }
}

