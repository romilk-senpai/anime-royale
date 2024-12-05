#include "celestial_body.h"
#include <stdlib.h>

CelestialBody *celestial_body_new(Vector2 *pos, float mass) {
  CelestialBody *body = malloc(sizeof(CelestialBody));
  *body = (CelestialBody){pos, vector2_zero(), vector2_zero(), mass};
  return body;
}
