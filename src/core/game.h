#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "GameObjectManager.h"
#include "input.h"
#include "player.h"
#include "time.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int quit;
  Time *time;
  Player *player;
  Input *input;
  GameObjectManager *gameObjectManager;
} GameState;

GameState *init_game();
void handle_time(GameState *state);
void process_input(GameState *state);
void update_game(GameState *state);
void render_game(GameState *state);
void quit_game(GameState *state);

#endif
