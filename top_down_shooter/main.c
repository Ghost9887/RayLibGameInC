#include "raylib.h"
#include <stdio.h>

//GLOBAL VARIABLES
const unsigned int SCREENWIDTH = 1200;
const unsigned int SCREENHEIGHT = 800;

typedef struct{
  int x;
  int y;
  int width;
  int height;
  int health;
}Player;

typedef struct{
  int x;
  int y;
  int width;
  int height;
  int health;
}Enemy;


void playerMovement(Player *player);
void createPlayerObject(Player *player);
void drawPlayer(Player *player);
void createEnemyObject(Enemy *enemy);
void drawEnemy(Enemy *enemy);


int main(void){

  InitWindow(SCREENWIDTH, SCREENHEIGHT, "raylib game");

  SetTargetFPS(60);

  //create the player
  Player player;
  createPlayerObject(&player);

  //create a enemy
  Enemy enemy1;
  createEnemyObject(&enemy1);

  while(!WindowShouldClose()){

    //call player movement
    playerMovement(&player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      DrawText(TextFormat("Health: %d", player.health), 25, 25, 40, LIGHTGRAY);

      drawPlayer(&player);

      drawEnemy(&enemy1);

    EndDrawing();
  }

  CloseWindow();

  return 0;

}


void playerMovement(Player *player){
    
  if(IsKeyDown(KEY_LEFT)) player->x -= 4.0f;
    
  if(IsKeyDown(KEY_RIGHT)) player->x += 4.0f;

  if(IsKeyDown(KEY_DOWN)) player->y += 4.0f;

  if(IsKeyDown(KEY_UP)) player->y -= 4.0f;
}

void createPlayerObject(Player *player){

  player->x = SCREENWIDTH / 2;

  player->y = SCREENHEIGHT / 2;

  player->width = 30;

  player->height = 50;

  player->health = 100;
}

void drawPlayer(Player *player){

  DrawRectangle(player->x, player->y, player->width, player->height, BLUE);

}

void createEnemyObject(Enemy *enemy){
  
  enemy->x = 200;
  
  enemy->y = 200;

  enemy->width = 30;

  enemy->height = 30;

  enemy->health = 100;
}

void drawEnemy(Enemy *enemy){

  DrawRectangle(enemy->x, enemy->y, enemy->width, enemy->height, RED);

}



