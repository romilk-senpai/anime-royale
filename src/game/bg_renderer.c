#include "bg_renderer.h"
#include "camera.h"
#include "gameobject.h"
#include "go_pool.h"
#include "vector2.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

BGRenderer *bg_renderer_new(GameState *state) {
  BGRenderer *bg_renderer = malloc(sizeof(BGRenderer));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), bg_renderer,
                             bg_renderer_update, bg_renderer_render);
  bg_renderer->go = go;

  SDL_Surface *surface = IMG_Load("assets/bg_space.png");
  bg_renderer->bg_tex = SDL_CreateTextureFromSurface(state->renderer, surface);
  SDL_FreeSurface(surface);

  go_pool_bind(state->go_pool, go);

  return bg_renderer;
}

static void bg_renderer_update(GameState *state, void *context) {}

static void bg_renderer_render(GameState *state, void *context) {
  BGRenderer *bg_renderer = (BGRenderer *)context;

  int bg_wdith = 640 * 3;
  int bg_height = 640 * 3;

  Vector2 world_zero = screen_to_world_pos(state->camera, vector2_zero());
  printf("%.1f %.1f\n", world_zero.x, world_zero.y);
  Vector2 bg_offset = world_to_screen_pos(
      state->camera, (Vector2){floor(world_zero.x / bg_wdith) * bg_wdith,
                               floor(world_zero.y / bg_height) * bg_height});
  int render_x = bg_offset.x;
  int render_y = bg_offset.y;

  printf("%d %d\n", render_x, render_y);

  while (render_x < state->camera->viewbox.x) {
    while (render_y < state->camera->viewbox.y) {
      SDL_Rect rect;
      rect.w = bg_wdith;
      rect.h = bg_height;
      rect.x = render_x;
      rect.y = render_y;

      SDL_RenderCopy(state->renderer, bg_renderer->bg_tex, NULL, &rect);

      render_y += bg_height;
    }
    render_y = bg_offset.y;
    render_x += bg_wdith;
  }
}
