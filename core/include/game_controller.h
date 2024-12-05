#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "gameobject.h"

struct GameState;

typedef void (*game_controller_func)(struct GameState *, void *);

typedef struct {
  void *binding;
  game_controller_func on_start;
  game_controller_func on_before_update;
  game_controller_func on_post_update;
  game_controller_func on_before_render;
  game_controller_func on_post_render;
} GameController;

#endif
