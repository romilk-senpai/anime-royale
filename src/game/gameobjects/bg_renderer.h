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
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);
void free_bg_renderer(BGRenderer *renderer, GameState *state);

#endif
