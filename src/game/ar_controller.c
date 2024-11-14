#include "ar_controller.h"
#include "game.h"
#include "game_controller.h"
#include "gameobjects/bg_renderer.h"
#include "gameobjects/cursor.h"
#include "gameobjects/player.h"
#include <stdlib.h>

ARController *ar_controller_new() {
  ARController *ar_controller = malloc(sizeof(ARController));
  GameController *game_controller = malloc(sizeof(GameController));
  *game_controller = (GameController){.binding = ar_controller,
                                      .on_start = start,
                                      .on_before_update = before_update,
                                      .on_post_update = post_update,
                                      .on_before_render = before_render,
                                      .on_post_render = post_render};
  ar_controller->game_controller = game_controller;
  return ar_controller;
}

static void start(GameState *state, void *context) {
  Player *player = player_new(state);
  Cursor *cursor = cursor_new(state);
  BGRenderer *renderer = bg_renderer_new(state);
}

static void before_update(GameState *state, void *context) {}

static void post_update(GameState *state, void *context) {}

static void before_render(GameState *state, void *context) {}

static void post_render(GameState *state, void *context) {}
