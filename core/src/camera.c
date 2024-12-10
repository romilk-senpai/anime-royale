#include "camera.h"

Vector2 screen_to_world_pos(Camera *self, Vector2 screen_pos) {
  Vector2 relative_screen_pos =
      vector2_sub(screen_pos, vector2_mul_scalar(self->viewbox, 0.5f));
  return vector2_add(relative_screen_pos, self->position);
}

Vector2 world_to_screen_pos(Camera *self, Vector2 world_pos) {
  Vector2 relative_world_pos = vector2_sub(world_pos, self->position);
  return vector2_add(relative_world_pos,
                     vector2_mul_scalar(self->viewbox, 0.5f));
}
