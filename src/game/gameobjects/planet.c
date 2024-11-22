#include "planet.h"
#include "../sdl_helper.h"
#include "celestial_body.h"
#include "player.h"
#include "vector2.h"
#include <SDL2/SDL_render.h>

Planet *planet_new(GameState *state, Vector2 position, Vector2 size) {
  Planet *planet = malloc(sizeof(Planet));
  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), planet, update, render);
  planet->go = go;
  planet->go->position = position;
  planet->size = size;
  planet->planet_tex = create_sdl_texture(state->renderer, "assets/planet.png");
  planet->celestial_body = celestial_body_new(&planet->go->position, 45.0f);
  SDL_SetTextureColorMod(planet->planet_tex, 102, 51, 153);
  go->z_index = 1;
  go_pool_bind(state->go_pool, go);
  return planet;
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {
  Planet *planet = (Planet *)context;
  SDL_Rect rect;
  rect.w = planet->size.x;
  rect.h = planet->size.y;
  Vector2 render_pos = world_to_screen_pos(
      state->camera, (Vector2){planet->go->position.x - rect.w / 2.0,
                               planet->go->position.y - rect.h / 2.0});
  rect.x = render_pos.x;
  rect.y = render_pos.y;
  SDL_RenderCopy(state->renderer, planet->planet_tex, NULL, &rect);
}
