#include "camera.h"
#include "vector2.h"
#include <stdlib.h>

Camera *camera_new(Vector2 screen_size) {
  Camera *camera = malloc(sizeof(Camera));

  *camera = (Camera){screen_size, vector2_zero()};

  return camera;
}

Vector2 screen_to_world_pos(Camera *camera, Vector2 screen_pos) {
  Vector2 relative_screen_pos =
      vector2_sub(screen_pos, vector2_mul_scalar(camera->viewbox, 0.5f));
  return vector2_add(relative_screen_pos, camera->position);
}

Vector2 world_to_screen_pos(Camera *camera, Vector2 world_pos) {
  Vector2 relative_world_pos = vector2_sub(world_pos, camera->position);
  return vector2_add(relative_world_pos,
                     vector2_mul_scalar(camera->viewbox, 0.5f));
}
