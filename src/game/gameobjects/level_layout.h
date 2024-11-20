#ifndef LEVEL_LAYOUT_H
#define LEVEL_LAYOUT_H

#include "gameobject.h"
#include <SDL2/SDL_rect.h>
#include <game.h>

typedef struct {
  GameObject *go;
} LevelLayout;

LevelLayout *level_layout_new(GameState *state);

#endif
