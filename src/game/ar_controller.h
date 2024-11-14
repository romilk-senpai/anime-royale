#ifndef AR_CONTROLLER_H
#define AR_CONTROLLER_H

#include "game.h"
#include "game_controller.h"

typedef struct {
  GameController *game_controller;
} ARController;

ARController *ar_controller_new();
static void start(GameState *state, void *context);
static void before_update(GameState *state, void *context);
static void post_update(GameState *state, void *context);
static void before_render(GameState *state, void *context);
static void post_render(GameState *state, void *context);

#endif
