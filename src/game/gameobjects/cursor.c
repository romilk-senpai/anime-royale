#include "cursor.h"
#include "gameobject.h"
#include "go_pool.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

Cursor *cursor_new(GameState *state) {
  Cursor *cursor = malloc(sizeof(Cursor));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), cursor,
                             update, render);
  cursor->go = go;
  go->z_index = 100;

  SDL_Surface *surface = IMG_Load("assets/cursor.png");
  cursor->cursor_tex = SDL_CreateTextureFromSurface(state->renderer, surface);
  SDL_FreeSurface(surface);

  go_pool_bind(state->go_pool, go);

  return cursor;
}

static void update(GameState *state, void *context) {
  Cursor *c = (Cursor *)context;
  c->go->position = state->input->mouse_pos;
}

static void render(GameState *state, void *context) {
  Cursor *cursor = (Cursor *)context;
  SDL_Rect rect;
  rect.w = 50;
  rect.h = 50;

  rect.x = cursor->go->position.x - rect.w / 2.0;
  rect.y = cursor->go->position.y - rect.h / 2.0;

  SDL_RenderCopy(state->renderer, cursor->cursor_tex, NULL, &rect);
}
