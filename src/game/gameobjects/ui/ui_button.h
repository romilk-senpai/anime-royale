#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "gameobject.h"
#include "game.h"
#include "vector2.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
  GameObject *go;
  Vector2 size;
  SDL_Texture *bg_tex;
  SDL_Texture *text_tex;
} UIButton;

UIButton *button_new(GameState *state, Vector2 size, char *bg_sprite_path,
                     char *text, TTF_Font *font, SDL_Color text_color);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
