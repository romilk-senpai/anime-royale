#ifndef UI_MAP_H
#define UI_MAP_H

#include "../level_layout.h"
#include "game.h"
#include "gameobject.h"
#include "vector2.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
  GameObject *go;
  LevelLayout *level_layout;
  Vector2 *player_pos;
  int isShowing;
} UIMap;

UIMap *ui_map_new(GameState *state, Vector2 *player_pos, LevelLayout *level_layout);
void ui_map_show(UIMap *map, GameState *state);
void ui_map_hide(UIMap *map, GameState *state);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
