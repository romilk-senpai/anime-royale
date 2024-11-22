#ifndef CELESTIAL_BODY_H
#define CELESTIAL_BODY_H

#include "vector2.h"

typedef struct {
  Vector2 *position;
  Vector2 velocity;
  Vector2 acceleration;
  float mass;
} CelestialBody;

CelestialBody *celestial_body_new(Vector2 *pos, float mass);

#endif
