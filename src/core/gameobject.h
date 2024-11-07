#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "game.h"
#include "vector2.h"
#include <stdint.h>

typedef void (*update_go)(GameState *, void *);
typedef void (*render_go)(GameState *, void *);

typedef struct {
  uint32_t instance_id;
  void *binding;
  Vector2 position;
  float angle;
  update_go update;
  render_go render;
} GameObject;

#endif
