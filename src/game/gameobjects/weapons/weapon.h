#ifndef WEAPON_H
#define WEAPON_H

#include "game.h"
#include "gameobject.h"

typedef void (*fire_func)(GameState *, void *);

typedef struct {
  GameObject *go;
  void *binding;
  fire_func fire;
} Weapon;

Weapon *weapon_new(GameObject *go, void *binding, fire_func fire);

#endif
