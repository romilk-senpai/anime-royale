#include "bg_renderer.h"
#include "../sdl_helper.h"
#include "camera.h"
#include "gameobject.h"
#include "go_pool.h"
#include "vector2.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

BGRenderer *bg_renderer_new(GameState *state) {
  BGRenderer *bg_renderer = malloc(sizeof(BGRenderer));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), bg_renderer, update, render);
  bg_renderer->go = go;
  go->z_index = 0;

  bg_renderer->bg_tex =
      create_sdl_texture(state->renderer, "assets/bg_space.png");

  go_pool_bind(state->go_pool, go);

  return bg_renderer;
}

static void update(void *self, GameState *state) {}

static void render(void *self, GameState *state) {
  BGRenderer *bg_renderer = (BGRenderer *)self;

  int bg_wdith = 640;
  int bg_height = 640;

  Vector2 world_zero = screen_to_world_pos(&state->camera, vector2_zero());
  Vector2 bg_offset = world_to_screen_pos(
      &state->camera, (Vector2){floor(world_zero.x / bg_wdith) * bg_wdith,
                               floor(world_zero.y / bg_height) * bg_height});
  int render_x = bg_offset.x;
  int render_y = bg_offset.y;

  while (render_x < state->camera.viewbox.x) {
    while (render_y < state->camera.viewbox.y) {
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

void free_bg_renderer(BGRenderer *renderer, GameState *state) {
  go_pool_unbind(state->go_pool, renderer->go);
  SDL_DestroyTexture(renderer->bg_tex);
  free(renderer->go);
  free(renderer);
}
