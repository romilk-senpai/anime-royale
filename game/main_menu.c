#include "main_menu.h"
#include "anigame.h"
#include "game.h"
#include "vector2.h"
#include <SDL2/SDL_ttf.h>

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

MainMenu *main_menu_new(GameState *state) {
  MainMenu *main_menu = malloc(sizeof(MainMenu));
  TTF_Font *font = TTF_OpenFont("assets/font.ttf", 18);
  if (!font) {
    SDL_Log("Unable to open font: %s", TTF_GetError());
  }
  Vector2 button_size = {240, 45};
  Vector2 center_offset =
      vector2_sub(vector2_mul_scalar(state->camera.viewbox, 0.5f),
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

// to where do you want quit in web?
#ifndef __EMSCRIPTEN__
  main_menu->exit_button =
      button_new(state, button_size, "assets/menu-button.png", "Exit", font,
                 (SDL_Color){0, 0, 0, 255});
  main_menu->exit_button->go->position =
      vector2_add(center_offset, (Vector2){0, 45});
  main_menu->exit_button->event_context = main_menu;
  main_menu->exit_button->onclick = onclick_exit;
#endif
  main_menu->bg_renderer = bg_renderer_new(state);
  TTF_CloseFont(font);
  return main_menu;
}

static void onclick_start(GameState *state, void *context) {
  anigame_new(state);
  main_menu_free((MainMenu *)context, state);
}

static void onclick_about(GameState *state, void *context) {
#ifdef __EMSCRIPTEN__
  emscripten_run_script("window.open('https://github.com/romilk-senpai/"
                        "anime-royale', '_blank');");
#elif defined(__linux__)
  system("xdg-open https://github.com/romilk-senpai/anime-royale");
#endif
}

static void onclick_exit(GameState *state, void *context) { state->quit = 1; }

static void main_menu_free(MainMenu *main_menu, GameState *state) {
  free_button(main_menu->start_game_button, state);
  free_button(main_menu->about_button, state);
#ifndef __EMSCRIPTEN__
  free_button(main_menu->exit_button, state);
#endif
  free_bg_renderer(main_menu->bg_renderer, state);
  free(main_menu);
}
