#include "game.h"
#include "drawables.h"
#include "input.h"
#include "vector2.h"
#include <SDL2/SDL.h>
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
  Player *player = new_player();
  Input *input = input_new();

  GameState *state = malloc(sizeof(GameState));

  *state = (GameState){window, renderer, 0, time, player, input};

  return state;
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
    in_move.y++;
  }
  if (keystate[SDL_SCANCODE_S]) {
    in_move.y--;
  }
  if (keystate[SDL_SCANCODE_A]) {
    in_move.x--;
  }
  if (keystate[SDL_SCANCODE_D]) {
    in_move.x++;
  }

  state->input->movement = vector2_normalize(in_move);
}

void update(GameState *state) {
  Vector2 movement = vector2_mul_scalar(state->input->movement, PLAYER_SPEED);
  movement = vector2_mul_scalar(movement, state->time->delta_time);
  state->player->position = vector2_add(state->player->position, movement);
}

void render(GameState *state) {
  SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
  SDL_RenderClear(state->renderer);

  SDL_SetRenderDrawColor(state->renderer, 255, 0, 0, 255);
  SDL_Rect player_rect = player_drawable(state->player);
  SDL_RenderFillRect(state->renderer, &player_rect);

  SDL_RenderPresent(state->renderer);
}

void quit(GameState *state) {
  SDL_DestroyRenderer(state->renderer);
  SDL_DestroyWindow(state->window);
  SDL_Quit();
}
