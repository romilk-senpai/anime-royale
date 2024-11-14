#ifndef PISTOL_H
#define PISTOL_H

#include "game.h"
#include "gameobject.h"
#include "weapon.h"
#include <SDL2/SDL_stdinc.h>

typedef struct {
  GameObject *go;
  Weapon *weapon;
  int current_ammo;
  int max_mag_ammo;
  float last_shot_time;
} Pistol;

Pistol *pistol_new(GameState *state);
static void fire(GameState *state, void *context);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
