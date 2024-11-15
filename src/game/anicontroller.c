#include "anicontroller.h"
#include "game.h"
#include "main_menu.h"
#include <stdlib.h>

AniController *anicontroller_new() {
  AniController *ar_controller = malloc(sizeof(AniController));
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
  MainMenu *main_menu = main_menu_new(state);
}

static void before_update(GameState *state, void *context) {}

static void post_update(GameState *state, void *context) {}

static void before_render(GameState *state, void *context) {}

static void post_render(GameState *state, void *context) {}
