#ifndef WEAPON_H
#define WEAPON_H

#include "game.h"
#include "gameobject.h"
#include <SDL2/SDL_render.h>

typedef void (*fire_func)(void *self, GameState *state);

typedef struct {
  GameObject *go;
  void *binding;
  fire_func fire;
  SDL_Texture *icon_tex;
} Weapon;

Weapon *weapon_new(GameObject *go, void *binding, fire_func fire);

#endif
