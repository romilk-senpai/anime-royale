#include "pistol.h"
#include "basic_bullet.h"
#include "game.h"
#include "weapon.h"

const float PISTOL_FIRE_RATE = 60.0;

Pistol *pistol_new(GameState *state) {
  Pistol *pistol = malloc(sizeof(Pistol));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), pistol,
                             pistol_update, pistol_render);

  Weapon *weapon = weapon_new(go, pistol, pistol_fire);
  pistol->go = go;
  pistol->weapon = weapon;

  go_pool_bind(state->go_pool, go);

  return pistol;
}

static void pistol_fire(GameState *state, void *context) {
  Pistol *pistol = (Pistol *)context;
  BasicBullet *bullet =
      bullet_new(state, pistol->go->position,
                 vector2_normalize(vector2_sub(state->input->mouse_pos,
                                               pistol->go->position)),
                 5.0f);
}

static void pistol_update(GameState *state, void *context) {}

static void pistol_render(GameState *state, void *context) {}
