#ifndef PLANET_H
#define PLANET_H

#include "game.h"
#include "gameobject.h"
#include "vector2.h"
#include <SDL2/SDL_render.h>

typedef struct {
  GameObject *go;
  SDL_Texture *planet_tex;
  Vector2 position;
  Vector2 size;
} Planet;

Planet *planet_new(GameState *state, Vector2 position, Vector2 size);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
