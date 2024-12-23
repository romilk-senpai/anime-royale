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
#include <SDL2/SDL_ttf.h>
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
  button->text_tex = create_sdl_text(state->renderer, font, text, text_color);
  go_pool_bind(state->go_pool, go);
  return button;
}

static void update(void *self, GameState *state) {
  UIButton *button = (UIButton *)self;
  Vector2 mouse_pos = state->input.mouse_pos;
  button->hovered = mouse_pos.x > button->go->position.y &&
                    mouse_pos.x < button->go->position.x + button->size.x &&
                    mouse_pos.y > button->go->position.y &&
                    mouse_pos.y < button->go->position.y + button->size.y;
  if (button->hovered && state->input.mouse_down) {
    if (button->onclick != NULL) {
      button->onclick(state, button->event_context);
    }
  }
}

static void render(void *self, GameState *state) {
  UIButton *button = (UIButton *)self;
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

void free_button(UIButton *button, GameState *state) {
  go_pool_unbind(state->go_pool, button->go);
  SDL_DestroyTexture(button->text_tex);
  SDL_DestroyTexture(button->bg_tex);
  free(button->go);
  free(button);
}
