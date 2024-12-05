#ifndef A_RIFLE_H
#define A_RIFLE_H

#include "game.h"
#include "gameobject.h"
#include "weapon.h"

typedef struct {
  GameObject *go;
  Weapon *weapon;
  float last_shot_time;
} AutoRifle;

AutoRifle *auto_rifle_new(GameState *state);
static void fire(void *self, GameState *state);
static void update(void *self, GameState *state);
static void render(void *self, GameState *state);

#endif
