#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "input.h"
#include "player.h"
#include "time.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float PLAYER_SPEED = 5;

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int quit;
  Time *time;
  Player *player;
  Input *input;
} GameState;

GameState *init_game();
void process_input(GameState *state);
void update(GameState *state);
void render(GameState *state);
void quit(GameState *state);

#endif
