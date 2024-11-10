#include "shotgun.h"
#include "basic_bullet.h"
#include "game.h"
#include "vector2.h"
#include "weapon.h"

const float shotgun_FIRE_RATE = 60.0;

Shotgun *shotgun_new(GameState *state) {
  Shotgun *shotgun = malloc(sizeof(Shotgun));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), shotgun,
                             shotgun_update, shotgun_render);

  Weapon *weapon = weapon_new(go, shotgun, shotgun_fire);
  shotgun->go = go;
  shotgun->weapon = weapon;

  go_pool_bind(state->go_pool, go);

  return shotgun;
}

static void shotgun_fire(GameState *state, void *context) {
  Shotgun *shotgun = (Shotgun *)context;

  Vector2 mouse_forward = vector2_normalize(
      vector2_sub(state->input->mouse_pos, shotgun->go->position));
  Vector2 mouse_left = vector2_rotate(mouse_forward, 30.0f);
  Vector2 mouse_right = vector2_rotate(mouse_forward, -30.0f);

  BasicBullet *bullet_f =
      bullet_new(state, shotgun->go->position, mouse_forward, 5.0f);
  BasicBullet *bullet_r =
      bullet_new(state, shotgun->go->position, mouse_left, 5.0f);
  BasicBullet *bullet_l =
      bullet_new(state, shotgun->go->position, mouse_right, 5.0f);
}

static void shotgun_update(GameState *state, void *context) {}

static void shotgun_render(GameState *state, void *context) {}
