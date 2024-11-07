#include "vector2.h"
#include <math.h>

Vector2 vector2_zero() {
  Vector2 v = {0.0, 0.0};
  return v;
}

Vector2 vector2_normalize(Vector2 v) {
  float magnitude = sqrt(v.x * v.x + v.y * v.y);
  if (magnitude != 0) {
    v.x /= magnitude;
    v.y /= magnitude;
  }
  return v;
}

Vector2 vector2_add(Vector2 v1, Vector2 v2) {
  return (Vector2){v1.x + v2.x, v1.y + v2.y};
}

Vector2 vector2_mul(Vector2 v1, Vector2 v2) {
  return (Vector2){v1.x * v2.x + v1.y * v2.y};
}

Vector2 vector2_mul_scalar(Vector2 v, float f) {
  return (Vector2){v.x * f, v.y * f};
}
