#ifndef GAME_H
#define GAME_H

#include "camera.h"
#include "game_controller.h"
#include "go_pool.h"
#include "input.h"
#include "time.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

typedef struct GameState {
  SDL_Window *window;
  SDL_Renderer *renderer;
  Camera *camera;
  int quit;
  GameController *game_controller;
  Time *time;
  Input *input;
  GOPool *go_pool;
} GameState;

GameState *init_game(GameController *game_controller);
void init_window(GameState *state, int window_width, int window_height);
int main_loop(GameState *state);

#ifdef __EMSCRIPTEN__
void game_run(void *state_ptr);
#else
void game_run(GameState *state);
#endif

void handle_time(GameState *state);
void process_input(GameState *state);
void update_game(GameState *state);
void render_game(GameState *state);
void quit_game(GameState *state);

#endif
