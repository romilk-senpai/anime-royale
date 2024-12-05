#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gameobject.h"
#include <SDL2/SDL_render.h>
#include <game.h>

typedef struct {
  GameObject *go;
  SDL_Texture *bg_tex;
} BGRenderer;

BGRenderer *bg_renderer_new(GameState *state);
static void update(void *self, GameState *state);
static void render(void *self, GameState *state);
void free_bg_renderer(BGRenderer *renderer, GameState *state);

#endif
