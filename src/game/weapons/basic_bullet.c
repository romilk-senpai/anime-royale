#include "basic_bullet.h"
#include <vector2.h>

const float BASIC_BULLET_SPEED = 1000.0f;

BasicBullet *bullet_new(GameState *state, Vector2 position, Vector2 direction,
                        float life_time) {
  BasicBullet *bullet = malloc(sizeof(BasicBullet));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), bullet,
                             bullet_update, bullet_render);
  go->position = position;

  bullet->go = go;
  bullet->direction = direction;
  bullet->life_time = life_time;

  go_pool_bind(state->go_pool, go);

  return bullet;
}

static void bullet_update(GameState *state, void *context) {
  BasicBullet *bullet = (BasicBullet *)context;
  bullet->go->position = vector2_add(
      bullet->go->position,
      vector2_mul_scalar(bullet->direction,
                         BASIC_BULLET_SPEED * state->time->delta_time));
}

static void bullet_render(GameState *state, void *context) {
  BasicBullet *bullet = (BasicBullet *)context;
  SDL_Rect rect;
  rect.w = 15;
  rect.h = 15;

  Vector2 render_pos = world_to_screen_pos(
      state->camera, (Vector2){bullet->go->position.x - rect.w / 2.0,
                               bullet->go->position.y - rect.h / 2.0});

  rect.x = render_pos.x;
  rect.y = render_pos.y;

  SDL_SetRenderDrawColor(state->renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(state->renderer, &rect);
}
