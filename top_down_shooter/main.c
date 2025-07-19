#include "raylib.h"
#include <stdio.h>

//GLOBAL VARIABLES
const unsigned int SCREENWIDTH = 1800;
const unsigned int SCREENHEIGHT = 1200;
unsigned int PROJECTILECOUNTER = 0;

typedef struct{
  int x;
  int y;
  int width;
  int height;
  int health;
  int ammo;
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


int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(60);

  //empty projectile array (MAX PROJECTILES AT ONCE IS 1000)
  Projectile projectileArr[1000];

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
      playerShoot(&player, projectileArr);
      for(int i = 0; i < PROJECTILECOUNTER; i++){
        moveProjectile(&projectileArr[i]);
        drawProjectile(&projectileArr[i]);
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

  if(IsKeyDown(KEY_SPACE)){
    projectileArr[PROJECTILECOUNTER] = createProjectile(player->x, player->y); 
  }

}

Projectile createProjectile(int posX, int posY){
  Projectile projectile;
  projectile.x = posX;
  projectile.y = posY;
  projectile.damage = 100;
  projectile.speed = 10;
  PROJECTILECOUNTER++;
  return projectile;
}

void drawProjectile(Projectile *projectile){
  DrawCircle(projectile->x, projectile->y, 20, GREEN);
}

void moveProjectile(Projectile *projectile){
  projectile->x += projectile->speed;
}




