#ifndef RADIAL_GUN_H
#define RADIAL_GUN_H

#include "game.h"
#include "gameobject.h"
#include "weapon.h"

typedef struct {
  GameObject *go;
  Weapon *weapon;
  float last_shot_time;
} RadGun;

RadGun *radgun_new(GameState *state);
static void fire(GameState *state, void *context);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
