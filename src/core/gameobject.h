#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector2.h"
#include <stdint.h>

struct GameState;

typedef void (*update_go)(struct GameState *, void *);
typedef void (*render_go)(struct GameState *, void *);

typedef struct {
  uint32_t instance_id;
  void *binding;
  Vector2 position;
  float angle;
  update_go update;
  render_go render;
} GameObject;

#endif
