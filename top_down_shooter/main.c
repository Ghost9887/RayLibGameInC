#include "raylib.h"
#include <stdio.h>
#include <stdbool.h>

//GLOBAL VARIABLES
const unsigned int SCREENWIDTH = 1500;
const unsigned int SCREENHEIGHT = 900;
const unsigned int TARGETFPS = 60;
unsigned int MAXPROJECTILES = 200;

typedef struct{
  int x;
  int y;
  int width;
  int height;
  int health;
  int ammo;
  float cooldown;
  float timer;
}Player;

typedef struct{
  int x;
  int y;
  int width;
  int height;
  int health;
}Enemy;

typedef struct{
  int x;
  int y;
  int damage;
  int speed;
  bool active;
  float lifetime;
}Projectile;


void drawUI(int health, int ammo);
void playerMovement(Player *player);
void enemyMovement(Enemy *enemy, Player *player);
void createPlayerObject(Player *player);
void drawPlayer(Player *player);
void createEnemyObject(Enemy *enemy, int posX, int posY, int width, int height, int health);
void drawEnemy(Enemy *enemy);
void playerShoot(Player *player, Projectile* projectileArrPtr);
Projectile createProjectile(int posX, int posY);
void drawProjectile(Projectile *projectile);
void moveProjectile(Projectile *projectile);
bool canFire(Player *player);

int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(TARGETFPS);

  Projectile projectileArr[MAXPROJECTILES];

  //create the player
  Player player;
  createPlayerObject(&player);

  //create a enemy
  Enemy enemy1;
  createEnemyObject(&enemy1, 200, 200, 30, 50, 100);

  Enemy enemy2;
  createEnemyObject(&enemy2, 100, 100, 30, 50, 100);

  while(!WindowShouldClose()){

    //call player movement
    playerMovement(&player);

    enemyMovement(&enemy1, &player);

    enemyMovement(&enemy2, &player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      drawUI(player.health, player.ammo);

      drawPlayer(&player);
      
      //if(canFire(&player)){   
      playerShoot(&player, projectileArr);
      //}

      //check the projectile array and update the pos of each projectile
      for(int i = 0; i < MAXPROJECTILES; i++){

        if(projectileArr[i].active){

          moveProjectile(&projectileArr[i]);

          drawProjectile(&projectileArr[i]);

          projectileArr[i].lifetime -= GetFrameTime();

          if(projectileArr[i].lifetime <= 0){

            projectileArr[i].active = false;

          }

        }
        
      }

      drawEnemy(&enemy1);
      drawEnemy(&enemy2);


    EndDrawing();
  }

  CloseWindow();

  return 0;

}

void drawUI(int health, int ammo){
  
  DrawText(TextFormat("Health: %d", health), 25, 25, 40, BLACK);
  
  DrawText(TextFormat("Ammo: %d", ammo), 25, 80, 40, BLACK);

}


void playerMovement(Player *player){

  float movementSpeed = 5.0f;
    
  if(IsKeyDown(KEY_A) && player->x > 0) player->x -= movementSpeed;
    
  if(IsKeyDown(KEY_D) && player->x + player->width < SCREENWIDTH) player->x += movementSpeed;

  if(IsKeyDown(KEY_S) && player->y + player->height < SCREENHEIGHT) player->y += movementSpeed;

  if(IsKeyDown(KEY_W) &&  player->y > 0) player->y -= movementSpeed;

}

void enemyMovement(Enemy *enemy, Player *player){
  
  float movementSpeed = 2.0f;
  
  if(enemy->x > player->x){
    enemy->x -= movementSpeed;
  }   
  if(enemy->y > player->y){
    enemy->y -= movementSpeed;
  }
  if(enemy->x < player->x){
    enemy->x += movementSpeed;
  }
  if(enemy->y < player->y){
    enemy->y += movementSpeed;
  }
  
}

void createPlayerObject(Player *player){

  player->x = SCREENWIDTH / 2;

  player->y = SCREENHEIGHT / 2;

  player->width = 30;

  player->height = 50;

  player->health = 100;

  player->ammo = 20000;

  player->cooldown = 0.1f;

  player->timer = player->cooldown * (float) TARGETFPS;
}

void drawPlayer(Player *player){

  DrawRectangle(player->x, player->y, player->width, player->height, BLUE);

}

void createEnemyObject(Enemy *enemy, int posX, int posY, int width, int height, int health){
  
  enemy->x = posX;
  
  enemy->y = posY;

  enemy->width = width;

  enemy->height = height;

  enemy->health = health;
}

void drawEnemy(Enemy *enemy){

  DrawRectangle(enemy->x, enemy->y, enemy->width, enemy->height, RED);

}

void playerShoot(Player *player, Projectile* projectileArr){
  
  //find a inactive projectile and replace it

  int indexToReplace;

  for(indexToReplace = 0; indexToReplace < MAXPROJECTILES; indexToReplace++){

    if(!projectileArr[indexToReplace].active){

      break;

    }

  }

  if(IsKeyDown(KEY_SPACE)){

    projectileArr[indexToReplace] = createProjectile(player->x, player->y); 

  }

}

Projectile createProjectile(int posX, int posY){

  Projectile projectile;

  projectile.x = posX;

  projectile.y = posY;

  projectile.damage = 100;

  projectile.speed = 10;

  projectile.active = true;

  projectile.lifetime = 2.0f;

  return projectile;

}

void drawProjectile(Projectile *projectile){

  DrawCircle(projectile->x, projectile->y, 20, GREEN);

}

void moveProjectile(Projectile *projectile){

  projectile->x += projectile->speed;

}





