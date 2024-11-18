#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct {
  float x, y;
} Vector2;

Vector2 vector2_zero();
Vector2 vector2_normalize(Vector2 v);
Vector2 vector2_add(Vector2 v1, Vector2 v2);
Vector2 vector2_sub(Vector2 v1, Vector2 v2);
Vector2 vector2_mul(Vector2 v1, Vector2 v2);
Vector2 vector2_mul_scalar(Vector2 v, float f);
Vector2 vector2_rotate(Vector2 v, float angle);
Vector2 vector2_rotate_rad(Vector2 v, float rad);
float vector2_magnitude(Vector2 v);

#endif
