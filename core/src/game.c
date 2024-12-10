#include "game.h"
#include "go_min_heap.h"
#include "input.h"
#include "time.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

const int LOGICAL_WIDTH = 1280;
const int LOGICAL_HEIGHT = 720;

GameState *init_game(GameController *game_controller) {
  Time time = {};
  Input input = {};
  GOPool *go_pool = go_pool_new();
  Camera camera = {LOGICAL_WIDTH, LOGICAL_HEIGHT};

  GameState *state = malloc(sizeof(GameState));

  *state =
      (GameState){NULL, NULL, camera, 0, game_controller, time, input, go_pool};

  return state;
}

void init_window(GameState *state, int window_width, int window_height) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("Anime Royale", 0, 0, window_width,
                                        window_height, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
#ifdef __EMSCRIPTEN__
  emscripten_set_canvas_size(window_width, window_height);
#endif
  SDL_RenderSetLogicalSize(renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);

  TTF_Init();
  IMG_Init(IMG_INIT_PNG);

  state->window = window;
  state->renderer = renderer;
}

int main_loop(GameState *state) {
  handle_time(state);
  handle_input(state);

  if (state->input.quit) {
    quit_game(state);
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

void handle_time(GameState *state) { time_handle(&state->time); }

void handle_input(GameState *state) { input_handle(&state->input); }

void update_go_map(key_value_pair *kvp, void *context) {
  GameState *state = (GameState *)context;
  uint32_t id = *(uint32_t *)kvp->key;
  GameObject *go = (GameObject *)kvp->value;
  go->update(go->binding, state);
}

void update_game(GameState *state) {
  hash_map_for_each(state->go_pool->go_map, update_go_map, state);
}

void render_go_map(key_value_pair *kvp, void *context) {
  GameState *state = (GameState *)context;
  GameObject *go = (GameObject *)kvp->value;
  go->render(go->binding, state);
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
    go->render(go->binding, state);
  }

  min_heap_free(heap);

  SDL_RenderPresent(state->renderer);
}

void quit_game(GameState *state) {
  SDL_DestroyRenderer(state->renderer);
  SDL_DestroyWindow(state->window);
  SDL_Quit();
}
