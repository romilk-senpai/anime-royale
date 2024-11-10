#include "weapon.h"
#include "gameobject.h"
#include <stdlib.h>

Weapon *weapon_new(GameObject *go, void *binding, fire fire) {
  Weapon *weapon = malloc(sizeof(Weapon));
  *weapon = (Weapon){.go = go, .binding = binding, .fire = fire};
  return weapon;
}
