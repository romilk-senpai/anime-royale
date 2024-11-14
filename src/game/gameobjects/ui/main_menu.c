#include "main_menu.h"
#include "go_pool.h"
#include "ui_button.h"
#include "vector2.h"
#include <SDL2/SDL_ttf.h>

MainMenu *main_menu_create(GameState *state) {
  MainMenu *main_menu = malloc(sizeof(MainMenu));
  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), main_menu, update, render);
  main_menu->go = go;
  TTF_Font *font = TTF_OpenFont("assets/font.ttf", 18);
  if (!font) {
    SDL_Log("Unable to open font: %s", TTF_GetError());
  }
  Vector2 button_size = {240, 45};
  Vector2 center_offset =
      vector2_sub(vector2_mul_scalar(state->camera->viewbox, 0.5f),
                  vector2_mul_scalar(button_size, 0.5f));
  main_menu->start_game_button =
      button_new(state, button_size, "assets/menu-button.png", "Start Game",
                 font, (SDL_Color){0, 0, 0, 255});
  main_menu->start_game_button->go->position =
      vector2_sub(center_offset, (Vector2){0, 45});
  main_menu->about_button =
      button_new(state, button_size, "assets/menu-button.png", "About",
                 font, (SDL_Color){0, 0, 0, 255});
  main_menu->about_button->go->position = center_offset;
  main_menu->exit_button =
      button_new(state, button_size, "assets/menu-button.png", "Exit",
                 font, (SDL_Color){0, 0, 0, 255});
  main_menu->exit_button->go->position =
      vector2_add(center_offset, (Vector2){0, 45});
  go_pool_bind(state->go_pool, main_menu->go);
  main_menu->bg_renderer = bg_renderer_new(state);
  TTF_CloseFont(font);
  return main_menu;
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {}
