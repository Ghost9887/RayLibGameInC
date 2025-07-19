#include "raylib.h"
#include <stdio.h>

//GLOBAL VARIABLES
const unsigned int SCREENHEIGHT = 1200;
const unsigned int SCREENWIDTH = 800;

struct Player {
  int x;
  int y;
  int width;
  int height;
  int health;
};

struct enemy{
  int x;
  int y;
  int width;
  int height;
  int health;
};


void playerMovement(struct Player *player);

struct Player createPlayerObject();

int main(void){

  InitWindow(SCREENHEIGHT, SCREENWIDTH, "raylib game");

  SetTargetFPS(60);

  struct Player player = createPlayerObject();

  while(!WindowShouldClose()){

    playerMovement(&player);

    BeginDrawing();

      ClearBackground(RAYWHITE);

      DrawText(TextFormat("Lives: %d", player.health), 50, 50, 20, LIGHTGRAY);

      DrawRectangle(player.x, player.y, player.width, player.height, BLUE);

    EndDrawing();

  }

  CloseWindow();

  return 0;

}


void playerMovement(struct Player *player){
    
  if(IsKeyDown(KEY_LEFT)) player->x -= 2.0f;
    
  if(IsKeyDown(KEY_RIGHT)) player->x += 2.0f;

  if(IsKeyDown(KEY_DOWN)) player->y += 2.0f;

  if(IsKeyDown(KEY_UP)) player->y -= 2.0f;
}

struct Player createPlayerObject(){

  struct Player player;

  player.x = SCREENWIDTH / 2;

  player.y = SCREENHEIGHT / 2;

  player.width = 30;

  player.height = 50;

  player.health = 100;

  return player;

}



