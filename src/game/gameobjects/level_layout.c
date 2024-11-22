#include "level_layout.h"
#include "planet.h"
#include "vector2.h"
#include <stdlib.h>

const float GRAVITY_CONSTANT = 0.1f;
const float STAR_MASS = 1000000;

LevelLayout *level_layout_new(GameState *state) {
  LevelLayout *layout = malloc(sizeof(LevelLayout));
  *layout = (LevelLayout){
      NULL,
      0,
  };
  return layout;
}

void level_layout_fill_basic(LevelLayout *layout, GameState *state) {
  layout->num_planets = 7;
  layout->planets = malloc(sizeof(Planet *) * layout->num_planets);
  for (size_t i = 0; i < layout->num_planets; i++) {
    float sp = ((float)i / layout->num_planets) * 2 * PI;
    float mid_dist = 3500.0f / layout->num_planets;
    float dist = 250 + mid_dist * (i + 1);
    double speed = sqrt(GRAVITY_CONSTANT * STAR_MASS / dist);
    layout->planets[i] =
        planet_new(state, (Vector2){dist * cosf(sp), dist * sinf(sp)},
                   (Vector2){250, 250});
    layout->planets[i]->celestial_body->velocity =
        (Vector2){-speed * sinf(sp), speed * cosf(sp)};
  }
  Planet *star = planet_new(state, vector2_zero(), (Vector2){100, 100});
  star->celestial_body->mass = STAR_MASS;
  layout->star = star;
}
