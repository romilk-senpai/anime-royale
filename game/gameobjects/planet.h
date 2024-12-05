#ifndef PLANET_H
#define PLANET_H

#include "celestial_body.h"
#include "game.h"
#include "gameobject.h"
#include "vector2.h"
#include <SDL2/SDL_render.h>

typedef struct {
  GameObject *go;
  SDL_Texture *planet_tex;
  Vector2 size;
  CelestialBody *celestial_body;
} Planet;

Planet *planet_new(GameState *state, Vector2 position, Vector2 size);
static void update(void *self, GameState *state);
static void render(void *self, GameState *state);

#endif
