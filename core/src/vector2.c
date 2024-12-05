#include "vector2.h"
#include <math.h>

Vector2 vector2_zero() { return (Vector2){0.0, 0.0}; }

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

Vector2 vector2_sub(Vector2 v1, Vector2 v2) {
  return (Vector2){v1.x - v2.x, v1.y - v2.y};
}

Vector2 vector2_mul(Vector2 v1, Vector2 v2) {
  return (Vector2){v1.x * v2.x + v1.y * v2.y};
}

Vector2 vector2_mul_scalar(Vector2 v, float f) {
  return (Vector2){v.x * f, v.y * f};
}

Vector2 vector2_rotate(Vector2 v, float angle) {
  float rad = angle * M_PI / 180.0f;
  return vector2_rotate_rad(v, rad);
}

Vector2 vector2_rotate_rad(Vector2 v, float rad) {
  float cos_theta = cos(rad);
  float sin_theta = sin(rad);
  return (Vector2){v.x * cos_theta - v.y * sin_theta,
                   v.x * sin_theta + v.y * cos_theta};
}

float vector2_magnitude(Vector2 v) { return sqrtf(v.x * v.x + v.y * v.y); }

Vector2 lerp(Vector2 a, Vector2 b, float t) {
  Vector2 result = {(1.0f - t) * a.x + t * b.x, (1.0f - t) * a.y + t * b.y};
  return vector2_normalize(result);
}
