#include "main_menu.h"
#include "anigame.h"
#include "vector2.h"
#include <SDL2/SDL_ttf.h>

MainMenu *main_menu_new(GameState *state) {
  MainMenu *main_menu = malloc(sizeof(MainMenu));
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
  main_menu->start_game_button->event_context = main_menu;
  main_menu->start_game_button->onclick = onclick_start;

  main_menu->about_button =
      button_new(state, button_size, "assets/menu-button.png", "About", font,
                 (SDL_Color){0, 0, 0, 255});
  main_menu->about_button->go->position = center_offset;
  main_menu->about_button->event_context = main_menu;
  main_menu->about_button->onclick = onclick_about;

  main_menu->exit_button =
      button_new(state, button_size, "assets/menu-button.png", "Exit", font,
                 (SDL_Color){0, 0, 0, 255});
  main_menu->exit_button->go->position =
      vector2_add(center_offset, (Vector2){0, 45});
  main_menu->bg_renderer = bg_renderer_new(state);
  main_menu->exit_button->event_context = main_menu;
  main_menu->exit_button->onclick = onclick_exit;

  TTF_CloseFont(font);
  return main_menu;
}

static void onclick_start(GameState *state, void *context) {
    anigame_new(state);
}

static void onclick_about(GameState *state, void *context) {}

static void onclick_exit(GameState *state, void *context) { state->quit = 1; }
