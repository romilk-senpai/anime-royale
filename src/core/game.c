#include "game.h"
#include "go_pool.h"
#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

GameState *init_game() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return NULL;
  }

  SDL_Window *window = SDL_CreateWindow(
      "2D Shooter Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return NULL;
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return NULL;
  }

  Time *time = time_new();
  Input *input = input_new();
  GOPool *go_pool = go_pool_new();

  GameState *state = malloc(sizeof(GameState));

  *state = (GameState){window, renderer, 0, time, input, go_pool};

  return state;
}

void handle_time(GameState *state) {
  Uint32 current_time = SDL_GetTicks();
  float delta_time = (current_time - state->time->last_time) / 1000.0f;
  state->time->delta_time = delta_time;
  state->time->last_time = current_time;
}

void process_input(GameState *state) {
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      state->quit = 1;
      return;
    }
  }

  const Uint8 *keystate = SDL_GetKeyboardState(NULL);
  Vector2 in_move = vector2_zero();
  if (keystate[SDL_SCANCODE_W]) {
    in_move.y--;
  }
  if (keystate[SDL_SCANCODE_S]) {
    in_move.y++;
  }
  if (keystate[SDL_SCANCODE_A]) {
    in_move.x--;
  }
  if (keystate[SDL_SCANCODE_D]) {
    in_move.x++;
  }

  state->input->movement = vector2_normalize(in_move);
}

void update_go_map(key_value_pair *kvp, void *context) {
  GameState *state = (GameState *)context;
  uint32_t id = *(uint32_t *)kvp->key;
  GameObject *go = *(GameObject **)kvp->value;
  go->update(state, go->binding);
}

void update_game(GameState *state) {
  hash_map_for_each(state->go_pool->go_map, update_go_map, state);
}

void render_go_map(key_value_pair *kvp, void *context) {
  GameState *state = (GameState *)context;
  GameObject *go = *(GameObject **)kvp->value;
  go->render(state, go->binding);
}

void render_game(GameState *state) {
  SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
  SDL_RenderClear(state->renderer);

  hash_map_for_each(state->go_pool->go_map, render_go_map, state);

  SDL_RenderPresent(state->renderer);
}

void quit_game(GameState *state) {
  SDL_DestroyRenderer(state->renderer);
  SDL_DestroyWindow(state->window);
  SDL_Quit();
}
