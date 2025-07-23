#include "player.h"
#include "projectile.h"
#include "raylib.h"

extern const unsigned int SCREENWIDTH;
extern const unsigned int SCREENHEIGHT;
extern const unsigned int TARGETFPS;
extern int MAXPROJECTILES;

Player createPlayerObject(){
  Player player;
  player.x = (float) SCREENWIDTH / (float) 2;
  player.y = (float) SCREENHEIGHT / (float) 2;
  player.width = 30;
  player.height = 50;
  player.health = 100;
  player.cooldown = 1.0f;
  player.timer = player.cooldown * (float) TARGETFPS;
  player.canShoot = false;
  player.invTime = 0.0f;
  player.range = 400.0f;
  return player;
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

void playerShoot(Player *player, Projectile* projectileArr, Enemy* enemyArr, Coins *coins){
  int indexToReplace;
  for(indexToReplace = 0; indexToReplace < MAXPROJECTILES; indexToReplace++){
    if(!projectileArr[indexToReplace].active){
      break;
    }
  }
  if(checkIfPlayerCanShoot(player)){
    player->canShoot = false;
    player->timer = player->cooldown * (float) TARGETFPS;
    projectileArr[indexToReplace] = createProjectile(enemyArr, player, coins); 
  }
}

bool checkIfPlayerCanShoot(Player *player) {
    if (!player->canShoot && player->timer > 0) {
        player->timer--;
        return false;
    }
    if (player->timer <= 0) {
        player->canShoot = true;
    }
  return true;
}

void playerLoseHealth(Enemy *enemy, Player *player){
    if (!isPlayerInvulnerable(player)) {
        player->health -= enemy->damage;
        player->invTime += 3.0f;
    }
}

void invTimer(Player *player){
  if(player->invTime > 0.0f){
  player->invTime -= GetFrameTime();
  }else{
    player->invTime = 0.0f;
  }
}


bool isPlayerInvulnerable(Player *player){
    if (player->invTime > 0.0f) {
        return true;
    }
    return false;
}

void updatePlayer(Player *player){
  playerMovement(player);
  drawPlayer(player);
  invTimer(player);
}




