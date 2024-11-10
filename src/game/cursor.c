#include "cursor.h"
#include "gameobject.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

Cursor *cursor_new(GameState *state) {
  Cursor *c = malloc(sizeof(Cursor));

  GameObject *go = malloc(sizeof(GameObject));
  *go = (GameObject){.instance_id = go_pool_new_id(state->go_pool),
                     .binding = c,
                     .position = vector2_zero(),
                     .angle = 0.0,
                     .update = cursor_update,
                     .render = cursor_render};
  c->go = go;

  SDL_Surface *surface = IMG_Load("assets/cursor.png");
  c->cursor_tex = SDL_CreateTextureFromSurface(state->renderer, surface);
  SDL_FreeSurface(surface);

  return c;
}

static void cursor_update(GameState *state, void *context) {
  Cursor *c = (Cursor *)context;
  c->go->position = state->input->mouse_pos;
}

static void cursor_render(GameState *state, void *context) {
  Cursor *cursor = (Cursor *)context;
  SDL_Rect rect;
  rect.w = 50;
  rect.h = 50;

  rect.x = cursor->go->position.x - rect.w / 2.0;
  rect.y = cursor->go->position.y - rect.h / 2.0;

  SDL_RenderCopy(state->renderer, cursor->cursor_tex, NULL, &rect);
}
