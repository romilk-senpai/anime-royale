#ifndef BASIC_BULLET_H
#define BASIC_BULLET_H

#include "game.h"
#include "gameobject.h"
#include <SDL2/SDL_stdinc.h>

typedef struct {
  GameObject *go;
  Vector2 direction;
  float life_time;
} BasicBullet;

BasicBullet *bullet_new(GameState *state, Vector2 position, Vector2 direction,
                        float life_time);
static void bullet_update(GameState *state, void *context);
static void bullet_render(GameState *state, void *context);

#endif
