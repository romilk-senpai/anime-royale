#ifndef WEAPON_H
#define WEAPON_H

#include "game.h"
#include "gameobject.h"

typedef void (*fire)(GameState *, void *);

typedef struct {
  GameObject *go;
  void *binding;
  fire fire;
} Weapon;

Weapon *weapon_new(GameObject *go, void *binding, fire fire);

#endif
