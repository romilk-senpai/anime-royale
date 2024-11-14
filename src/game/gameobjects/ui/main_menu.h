#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "game.h"
#include "gameobject.h"
#include "ui_button.h"
#include "../bg_renderer.h"

typedef struct {
  GameObject *go;
  UIButton *start_game_button;
  UIButton *about_button;
  UIButton *exit_button;
  BGRenderer *bg_renderer;
} MainMenu;

MainMenu *main_menu_create(GameState *state);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
