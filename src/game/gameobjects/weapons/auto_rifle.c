#include "auto_rifle.h"
#include "../../sdl_helper.h"
#include "basic_bullet.h"

const float AUTO_RIFLE_FIRE_RATE = 8.0f;

AutoRifle *auto_rifle_new(GameState *state) {
  AutoRifle *a_rifle = malloc(sizeof(AutoRifle));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), a_rifle, update, render);

  Weapon *weapon = weapon_new(go, a_rifle, fire);
  TTF_Font *font = TTF_OpenFont("assets/font.ttf", 18);
  weapon->icon_tex =
      create_sdl_text(state->renderer, font, "AR", (SDL_Color){0, 0, 0, 255});
  TTF_CloseFont(font);
  a_rifle->go = go;
  a_rifle->weapon = weapon;

  go_pool_bind(state->go_pool, go);

  return a_rifle;
}

static void fire(GameState *state, void *context) {
  AutoRifle *a_rifle = (AutoRifle *)context;

  if (state->time->time - a_rifle->last_shot_time <
      1.0f / AUTO_RIFLE_FIRE_RATE) {
    return;
  }

  Vector2 direction = vector2_normalize(
      vector2_sub(state->input->mouse_pos,
                  world_to_screen_pos(state->camera, a_rifle->go->position)));

  BasicBullet *bullet =
      bullet_new(state, a_rifle->go->position, direction, 0.5f);

  a_rifle->last_shot_time = state->time->time;
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {}
