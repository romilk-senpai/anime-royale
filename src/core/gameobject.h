#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "vector2.h"
#include <stdint.h>

struct GameState;

typedef void (*update_func)(struct GameState *, void *);
typedef void (*render_func)(struct GameState *, void *);

typedef struct {
  uint32_t instance_id;
  void *binding;
  Vector2 position;
  float angle;
  update_func update;
  render_func render;
} GameObject;

GameObject *go_create(uint32_t instance_id, void *binding, update_func update,
                      render_func render);

#endif
