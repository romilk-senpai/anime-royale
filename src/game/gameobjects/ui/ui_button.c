#include "ui_button.h"
#include "../../sdl_helper.h"
#include "game.h"
#include "go_pool.h"
#include "vector2.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdlib.h>

UIButton *button_new(GameState *state, Vector2 size, char *bg_sprite_path,
                     char *text, TTF_Font *font, SDL_Color text_color) {
  UIButton *button = malloc(sizeof(UIButton));
  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), button, update, render);
  go->z_index = 100;
  button->go = go;
  button->bg_tex = create_sdl_texture(state->renderer, bg_sprite_path);
  button->size = size;
  button->hovered = 0;
  SDL_Surface *text_surf = TTF_RenderText_Solid(font, text, text_color);
  button->text_tex = SDL_CreateTextureFromSurface(state->renderer, text_surf);
  SDL_FreeSurface(text_surf);
  go_pool_bind(state->go_pool, go);
  return button;
}

static void update(GameState *state, void *context) {
  UIButton *button = (UIButton *)context;
  Vector2 mouse_pos = state->input->mouse_pos;
  button->hovered = mouse_pos.x > button->go->position.y &&
                    mouse_pos.x < button->go->position.x + button->size.x &&
                    mouse_pos.y > button->go->position.y &&
                    mouse_pos.y < button->go->position.y + button->size.y;
}

static void render(GameState *state, void *context) {
  UIButton *button = (UIButton *)context;
  if (button->hovered) {
    SDL_SetTextureAlphaMod(button->bg_tex, 200);
  } else {
    SDL_SetTextureAlphaMod(button->bg_tex, 255);
  }

  SDL_Rect spriteRect = {button->go->position.x, button->go->position.y,
                         button->size.x, button->size.y};
  SDL_RenderCopy(state->renderer, button->bg_tex, NULL, &spriteRect);

  int text_width, text_height;
  SDL_QueryTexture(button->text_tex, NULL, NULL, &text_width, &text_height);
  SDL_Rect text_rect = {
      button->go->position.x + (button->size.x - text_width) / 2,
      button->go->position.y + (button->size.y - text_height) / 2, text_width,
      text_height};
  SDL_RenderCopy(state->renderer, button->text_tex, NULL, &text_rect);
}
