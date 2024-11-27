#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include "game.h"
#include "gameobject.h"
#include "vector2.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

typedef void (*onclick_func)(GameState *, void *);

typedef struct {
  GameObject *go;
  Vector2 size;
  SDL_Texture *bg_tex;
  SDL_Texture *text_tex;
  int hovered;
  void *event_context;
  onclick_func onclick;
} UIButton;

UIButton *button_new(GameState *state, Vector2 size, char *bg_sprite_path,
                     char *text, TTF_Font *font, SDL_Color text_color);
static void update(void *self, GameState *state);
static void render(void *self, GameState *state);
void free_button(UIButton *button, GameState *state);

#endif
