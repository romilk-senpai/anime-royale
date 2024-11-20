#include "level_layout.h"
#include <stdlib.h>

LevelLayout *level_layout_new(GameState *state) {
  LevelLayout *layout = malloc(sizeof(LevelLayout));
  return layout;
}
