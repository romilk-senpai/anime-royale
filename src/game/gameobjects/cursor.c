#include "cursor.h"
#include "gameobject.h"
#include "go_pool.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include "../sdl_helper.h"

Cursor *cursor_new(GameState *state) {
  Cursor *cursor = malloc(sizeof(Cursor));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), cursor,
                             update, render);
  cursor->go = go;
  go->z_index = 1000;

  cursor->cursor_tex = create_sdl_texture(state->renderer, "assets/cursor.png");

  go_pool_bind(state->go_pool, go);

  return cursor;
}

static void update(void *self, GameState *state) {
  Cursor *c = (Cursor *)self;
  c->go->position = state->input->mouse_pos;
}

static void render(void *self, GameState *state) {
  Cursor *cursor = (Cursor *)self;
  SDL_Rect rect;
  rect.w = 50;
  rect.h = 50;

  rect.x = cursor->go->position.x - rect.w / 2.0;
  rect.y = cursor->go->position.y - rect.h / 2.0;

  SDL_RenderCopy(state->renderer, cursor->cursor_tex, NULL, &rect);
}
