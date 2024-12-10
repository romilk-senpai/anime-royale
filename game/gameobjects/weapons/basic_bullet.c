#include "basic_bullet.h"
#include "go_pool.h"
#include <SDL2/SDL_stdinc.h>
#include <stdlib.h>
#include <vector2.h>

const float BASIC_BULLET_SPEED = 1000.0f;

BasicBullet *bullet_new(GameState *state, Vector2 position, Vector2 direction,
                        float life_time) {
  BasicBullet *bullet = malloc(sizeof(BasicBullet));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), bullet, update, render);
  go->position = position;
  go->z_index = 15;
  SDL_log(go->z_index);

  bullet->go = go;
  bullet->direction = direction;
  bullet->destroy_time = state->time.time + life_time;

  go_pool_bind(state->go_pool, go);

  return bullet;
}

static void update(void *self, GameState *state) {
  BasicBullet *bullet = (BasicBullet *)self;
  if (state->time.time > bullet->destroy_time) {
    bullet_free(bullet, state);
    return;
  }
  bullet->go->position = vector2_add(
      bullet->go->position,
      vector2_mul_scalar(bullet->direction,
                         BASIC_BULLET_SPEED * state->time.delta_time));
}

static void render(void *self, GameState *state) {
  BasicBullet *bullet = (BasicBullet *)self;
  SDL_Rect rect;
  rect.w = 15;
  rect.h = 15;

  Vector2 render_pos = world_to_screen_pos(
      &state->camera, (Vector2){bullet->go->position.x - rect.w / 2.0,
                               bullet->go->position.y - rect.h / 2.0});

  rect.x = render_pos.x;
  rect.y = render_pos.y;

  SDL_SetRenderDrawColor(state->renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(state->renderer, &rect);
}

void bullet_free(BasicBullet *bullet, GameState *state) {
  go_pool_unbind(state->go_pool, bullet->go);
  free(bullet->go);
  free(bullet);
}
