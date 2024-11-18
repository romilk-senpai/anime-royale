#include "planet.h"
#include "../sdl_helper.h"
#include "vector2.h"

Planet *planet_new(GameState *state, Vector2 position, Vector2 size) {
  Planet *planet = malloc(sizeof(Planet));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), planet, update, render);
  planet->go = go;
  go->z_index = 1;

  planet->planet_tex = create_sdl_texture(state->renderer, "assets/planet.png");

  go_pool_bind(state->go_pool, go);

  return planet;
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {
  Planet *planet = (Planet *)context;
  SDL_Rect rect;
  rect.w = planet->size.x;
  rect.h = planet->size.y;

  rect.x = planet->go->position.x - rect.w / 2.0;
  rect.y = planet->go->position.y - rect.h / 2.0;

  SDL_RenderCopy(state->renderer, planet->planet_tex, NULL, &rect);
}
