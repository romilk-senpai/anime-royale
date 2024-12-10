#include "radial_gun.h"
#include "../../sdl_helper.h"
#include "basic_bullet.h"
#include "vector2.h"
#include <SDL2/SDL_ttf.h>

const float PI = 3.141592653589793;
const float RADGUN_FIRE_RATE = 1.0f;
const int NUM_DIRECTIONS = 8;

RadGun *radgun_new(GameState *state) {
  RadGun *radgun = malloc(sizeof(RadGun));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), radgun, update, render);

  Weapon *weapon = weapon_new(go, radgun, fire);
  TTF_Font *font = TTF_OpenFont("assets/font.ttf", 18);
  weapon->icon_tex =
      create_sdl_text(state->renderer, font, "R", (SDL_Color){0, 0, 0, 255});
  TTF_CloseFont(font);
  radgun->go = go;
  radgun->weapon = weapon;

  go_pool_bind(state->go_pool, go);

  return radgun;
}

static void fire(void *self, GameState *state) {
  RadGun *radgun = (RadGun *)self;
  if (state->time.time - radgun->last_shot_time < 1.0f / RADGUN_FIRE_RATE) {
    return;
  }

  Vector2 mouse_forward = vector2_normalize(
      vector2_sub(state->input.mouse_pos,
                  world_to_screen_pos(&state->camera, radgun->go->position)));

  float angle_step = (2 * PI) / NUM_DIRECTIONS;

  for (int i = 0; i < NUM_DIRECTIONS; i++) {
    float angle = i * angle_step;
    Vector2 dir = vector2_rotate_rad(mouse_forward, angle);
    BasicBullet *bullet = bullet_new(state, radgun->go->position, dir, 0.35f);
  }

  radgun->last_shot_time = state->time.time;
}

static void update(void *self, GameState *state) {}

static void render(void *self, GameState *state) {}
