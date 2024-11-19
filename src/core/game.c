#include "game.h"
#include "camera.h"
#include "gameobject.h"
#include "go_min_heap.h"
#include "go_pool.h"
#include "map.h"
#include "vector.h"
#include "vector2.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

const int LOGICAL_WIDTH = 1280;
const int LOGICAL_HEIGHT = 720;

GameState *init_game(GameController *game_controller) {
  Time *time = time_new();
  Input *input = input_new();
  GOPool *go_pool = go_pool_new();
  Camera *camera = camera_new((Vector2){LOGICAL_WIDTH, LOGICAL_HEIGHT});

  GameState *state = malloc(sizeof(GameState));

  *state =
      (GameState){NULL, NULL, camera, 0, game_controller, time, input, go_pool};

  return state;
}

void init_window(GameState *state, int window_width, int window_height) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("Anime Royale", 0, 0, window_width,
                                        window_height, SDL_WINDOW_SHOWN);

#ifdef __EMSCRIPTEN__
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  emscripten_set_canvas_size(window_width, window_height);
#else
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
#endif
  SDL_RenderSetLogicalSize(renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);

  TTF_Init();
  IMG_Init(IMG_INIT_PNG);

  state->window = window;
  state->renderer = renderer;
}

int main_loop(GameState *state) {
  handle_time(state);
  process_input(state);
  if (state->quit == 1) {
    return 0;
  }

  state->game_controller->on_before_update(state,
                                           state->game_controller->binding);
  update_game(state);
  state->game_controller->on_post_update(state,
                                         state->game_controller->binding);

  state->game_controller->on_before_render(state,
                                           state->game_controller->binding);
  render_game(state);
  state->game_controller->on_post_render(state,
                                         state->game_controller->binding);
  return 1;
}

#ifdef __EMSCRIPTEN__
int should_init_window = 1;

void game_run(void *state_ptr) {
  GameState *state = (GameState *)state_ptr;
  if (should_init_window == 1) {
    init_window(state, LOGICAL_WIDTH, LOGICAL_HEIGHT);
    state->game_controller->on_start(state, state->game_controller->binding);
    should_init_window = 0;
    int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    int initted = IMG_Init(flags);
  }
  main_loop(state);
}
#else
void game_run(GameState *state) {
  init_window(state, LOGICAL_WIDTH, LOGICAL_HEIGHT);
  state->game_controller->on_start(state, state->game_controller->binding);
  while (main_loop(state) == 1) {
  }
  quit_game(state);
}
#endif

void handle_time(GameState *state) {
  Uint32 current_time = SDL_GetTicks();
  float delta_time = (current_time - state->time->last_time) / 1000.0f;
  state->time->time = current_time / 1000.0f;
  state->time->delta_time = delta_time;
  state->time->last_time = current_time;
}

void process_input(GameState *state) {
  state->input->mouse_held = 0;
  state->input->mouse_down = 0;
  *state->input->item_slot_input = (ItemSoltInput){0, 0, 0, 0};

  SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    switch (e.type) {
    case SDL_QUIT:
      state->quit = 1;
      return;

    case SDL_WINDOWEVENT:
      if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
        // state->camera->viewbox = (Vector2){e.window.data1, e.window.data2};
        break;
      }
    case SDL_MOUSEMOTION:
      state->input->mouse_pos = (Vector2){e.motion.x, e.motion.y};
      break;

    case SDL_KEYDOWN:
      switch (e.key.keysym.sym) {
      case SDLK_1:
        state->input->item_slot_input->item1 = 1;
      case SDLK_2:
        state->input->item_slot_input->item2 = 1;
      case SDLK_3:
        state->input->item_slot_input->item3 = 1;
      case SDLK_4:
        state->input->item_slot_input->item4 = 1;
      }
    case SDL_MOUSEBUTTONDOWN:
      if (e.button.button == SDL_BUTTON_LEFT) {
        state->input->mouse_down = 1;
      }
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

  int mouses_x, mouses_y;
  Uint32 mousestate = SDL_GetRelativeMouseState(&mouses_x, &mouses_y);
  state->input->mouse_held = mousestate & SDL_BUTTON(SDL_BUTTON_LEFT);
  // state->input->mouse_pos = (Vector2){mouse_x, mouse_y};
  state->input->movement = vector2_normalize(in_move);
}

void update_go_map(key_value_pair *kvp, void *context) {
  GameState *state = (GameState *)context;
  uint32_t id = *(uint32_t *)kvp->key;
  GameObject *go = (GameObject *)kvp->value;
  go->update(state, go->binding);
}

void update_game(GameState *state) {
  hash_map_for_each(state->go_pool->go_map, update_go_map, state);
}

void render_go_map(key_value_pair *kvp, void *context) {
  GameState *state = (GameState *)context;
  GameObject *go = (GameObject *)kvp->value;
  go->render(state, go->binding);
}

void render_create_min_heap(key_value_pair *kvp, void *context) {
  min_heap *heap = (min_heap *)context;
  min_heap_insert(heap, (GameObject *)kvp->value);
}

void render_game(GameState *state) {
  SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
  SDL_RenderClear(state->renderer);

  min_heap *heap = min_heap_new_cap(state->go_pool->go_map->size);
  hash_map_for_each(state->go_pool->go_map, render_create_min_heap, heap);
  while (heap->v->size > 0) {
    GameObject *go = min_heap_remove_min(heap);
    go->render(state, go->binding);
  }

  min_heap_free(heap);

  SDL_RenderPresent(state->renderer);
}

void quit_game(GameState *state) {
  SDL_DestroyRenderer(state->renderer);
  SDL_DestroyWindow(state->window);
  SDL_Quit();
}
