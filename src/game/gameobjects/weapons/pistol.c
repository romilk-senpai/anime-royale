#include "pistol.h"
#include "basic_bullet.h"
#include "camera.h"
#include "game.h"
#include "vector2.h"
#include "weapon.h"

const float PISTOL_FIRE_RATE = 3.0f;

Pistol *pistol_new(GameState *state) {
  Pistol *pistol = malloc(sizeof(Pistol));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), pistol, update, render);

  Weapon *weapon = weapon_new(go, pistol, fire);
  pistol->go = go;
  pistol->weapon = weapon;

  go_pool_bind(state->go_pool, go);

  return pistol;
}

static void fire(GameState *state, void *context) {
  Pistol *pistol = (Pistol *)context;

  if (state->time->time - pistol->last_shot_time < 1.0f / PISTOL_FIRE_RATE) {
    return;
  }

  Vector2 direction = vector2_normalize(
      vector2_sub(state->input->mouse_pos,
                  world_to_screen_pos(state->camera, pistol->go->position)));

  BasicBullet *bullet =
      bullet_new(state, pistol->go->position, direction, 0.5f);

  pistol->last_shot_time = state->time->time;
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {}
