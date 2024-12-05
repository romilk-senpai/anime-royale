#ifndef GRAVITY_SIM_H
#define GRAVITY_SIM_H

#include "game.h"
#include "level_layout.h"
#include "player.h"
#include "vector.h"

typedef struct {
  GameObject *go;
  vector *sim_bodies;
} GravitySim;

GravitySim *gravity_sim_new(GameState *state, Player *player,
                            LevelLayout *layout);
static void update(void *self, GameState *state);
static void render(void *self, GameState *state);

#endif
