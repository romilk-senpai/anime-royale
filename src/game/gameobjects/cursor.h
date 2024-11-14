#ifndef CURSOR_H
#define CURSOR_H

#include "gameobject.h"
#include <SDL2/SDL_rect.h>
#include <game.h>

typedef struct {
  GameObject *go;
  SDL_Texture *cursor_tex;
} Cursor;

Cursor *cursor_new(GameState *state);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
