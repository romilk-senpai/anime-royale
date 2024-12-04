#ifndef CAMERA_H
#define CAMERA_H

#include "vector2.h"

typedef struct {
  Vector2 viewbox;
  Vector2 position;
} Camera;

Camera camera_new(Vector2 screen_size);
Vector2 screen_to_world_pos(Camera *camera, Vector2 screen_pos);
Vector2 world_to_screen_pos(Camera *camera, Vector2 world_pos);

#endif
