#ifndef LEVEL_LAYOUT_H
#define LEVEL_LAYOUT_H

#define PI 3.14159265359

#include "planet.h"
#include <SDL2/SDL_rect.h>
#include <game.h>

typedef struct {
  Planet **planets;
  int num_planets;
  Planet *star;
} LevelLayout;

LevelLayout *level_layout_new(GameState *state);
void level_layout_fill_basic(LevelLayout *layout, GameState *state);

#endif
