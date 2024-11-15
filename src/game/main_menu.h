#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "game.h"
#include "gameobjects/bg_renderer.h"
#include "gameobjects/ui/ui_button.h"

typedef struct {
  UIButton *start_game_button;
  UIButton *about_button;
  UIButton *exit_button;
  BGRenderer *bg_renderer;
} MainMenu;

MainMenu *main_menu_new(GameState *state);
static void onclick_start(GameState *state, void *context);
static void onclick_about(GameState *state, void *context);
static void onclick_exit(GameState *state, void *context);
static void main_menu_free(MainMenu *main_menu, GameState *state);

#endif
