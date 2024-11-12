#include "camera.h"
#include "vector2.h"
#include <stdlib.h>

Camera *camera_new(Vector2 screen_size) {
  Camera *camera = malloc(sizeof(Camera));

  *camera = (Camera){screen_size, vector2_zero()};

  return camera;
}

Vector2 screen_to_world_pos(Camera *camera, Vector2 screen_pos) {
  return vector2_sub(
      screen_pos,
      vector2_add(camera->position, vector2_mul_scalar(camera->viewbox, 0.5f)));
}

Vector2 world_to_screen_pos(Camera *camera, Vector2 world_pos) {
  return vector2_add(vector2_sub(world_pos, camera->position),
                     vector2_mul_scalar(camera->viewbox, 0.5f));
}
