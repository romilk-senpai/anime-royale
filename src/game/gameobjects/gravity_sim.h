#ifndef GRAVITY_SIM_H
#define GRAVITY_SIM_H

#include "game.h"
#include "level_layout.h"
#include "vector.h"

typedef struct {
  GameObject *go;
  vector *sim_bodies;
} GravitySim;

GravitySim *gravity_sim_new(GameState *state, LevelLayout *layout);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
