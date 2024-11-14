#include "shotgun.h"
#include "basic_bullet.h"
#include "camera.h"
#include "game.h"
#include "vector2.h"
#include "weapon.h"

const float SHOTGUN_FIRE_RATE = 2.0f;

Shotgun *shotgun_new(GameState *state) {
  Shotgun *shotgun = malloc(sizeof(Shotgun));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), shotgun,
                             update, render);

  Weapon *weapon = weapon_new(go, shotgun, fire);
  shotgun->go = go;
  shotgun->weapon = weapon;

  go_pool_bind(state->go_pool, go);

  return shotgun;
}

static void fire(GameState *state, void *context) {
  Shotgun *shotgun = (Shotgun *)context;

  if (state->time->time - shotgun->last_shot_time < 1.0f / SHOTGUN_FIRE_RATE) {
    return;
  }

  Vector2 mouse_forward = vector2_normalize(
      vector2_sub(state->input->mouse_pos,
                  world_to_screen_pos(state->camera, shotgun->go->position)));
  Vector2 mouse_left = vector2_rotate(mouse_forward, 30.0f);
  Vector2 mouse_right = vector2_rotate(mouse_forward, -30.0f);

  BasicBullet *bullet_f =
      bullet_new(state, shotgun->go->position, mouse_forward, 5.0f);
  BasicBullet *bullet_r =
      bullet_new(state, shotgun->go->position, mouse_left, 5.0f);
  BasicBullet *bullet_l =
      bullet_new(state, shotgun->go->position, mouse_right, 5.0f);

  shotgun->last_shot_time = state->time->time;
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {}
