#include "level_layout.h"
#include "planet.h"
#include "vector2.h"
#include <stdlib.h>

LevelLayout *level_layout_new(GameState *state) {
  LevelLayout *layout = malloc(sizeof(LevelLayout));
  *layout = (LevelLayout){
      NULL,
      0,
  };
  return layout;
}

void level_layout_fill_basic(LevelLayout *layout, GameState *state) {
  layout->num_planets = 9;
  layout->planets =
      realloc(layout->planets, sizeof(Planet *) * layout->num_planets);
  for (size_t i = 0; i < layout->num_planets; i++) {
    float sp = ((float)i / layout->num_planets) * 2 * PI;
    float dist = 3500.0f / layout->num_planets;
    layout->planets[i] = planet_new(
        state, (Vector2){250 + dist * (i + 1) * cosf(sp), 250 + dist * (i + 1) * sinf(sp)},
        (Vector2){250, 250});
  }
}
