#ifndef BASIC_BULLET_H
#define BASIC_BULLET_H

#include "game.h"
#include "gameobject.h"

typedef struct {
  GameObject *go;
  Vector2 direction;
  float destroy_time;
} BasicBullet;

BasicBullet *bullet_new(GameState *state, Vector2 position, Vector2 direction,
                        float life_time);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);
void bullet_free(BasicBullet *bullet, GameState *state);

#endif
