#include "player.h"
#include "../sdl_helper.h"
#include "celestial_body.h"
#include "ui/ui_map.h"
#include "vector2.h"
#include "weapons/auto_rifle.h"
#include "weapons/pistol.h"
#include "weapons/radial_gun.h"
#include "weapons/shotgun.h"
#include "weapons/weapon.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

const float MAX_SPEED = 350.0f;
const float ACCELERATION = 350.0f;
const float FRICTION = 0.8f;

Player *player_new(GameState *state) {
  Player *player = malloc(sizeof(Player));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), player, update, render);
  player->go = go;
  go->z_index = 10;
  go->position = (Vector2){1000, 1000};

  Pistol *pistol = pistol_new(state);
  Shotgun *shotgun = shotgun_new(state);
  RadGun *radgun = radgun_new(state);
  AutoRifle *a_rifle = auto_rifle_new(state);

  player->weapon_inv = malloc(sizeof(Weapon) * 4);
  player->weapon_inv[0] = pistol->weapon;
  player->weapon_inv[1] = shotgun->weapon;
  player->weapon_inv[2] = radgun->weapon;
  player->weapon_inv[3] = a_rifle->weapon;
  player->weapon = player->weapon_inv[0];

  player->c_f_tex = create_sdl_texture(state->renderer, "assets/gooba2.png");
  player->h_f_tex = create_sdl_texture(state->renderer, "assets/h_front.png");
  player->c_b_tex = create_sdl_texture(state->renderer, "assets/c_back.png");
  player->h_b_tex = create_sdl_texture(state->renderer, "assets/h_back.png");

  player->movement = vector2_zero();
  player->celestial_body = celestial_body_new(&player->go->position, 45.0f);

  go_pool_bind(state->go_pool, go);

  return player;
}

static void update(void *self, GameState *state) {
  Player *player = (Player *)self;
  player->movement =
      vector2_add(player->movement,
                  vector2_mul_scalar(state->input.movement,
                                     ACCELERATION * state->time.delta_time));
  player->movement = vector2_mul_scalar(player->movement,
                                        pow(FRICTION, state->time.delta_time));
  float speed = vector2_magnitude(player->movement);
  if (speed > MAX_SPEED) {
    player->movement.x = (player->movement.x / speed) * MAX_SPEED;
    player->movement.y = (player->movement.y / speed) * MAX_SPEED;
  }

  Vector2 movement =
      vector2_mul_scalar(player->movement, state->time.delta_time);
  player->go->position = vector2_add(player->go->position, movement);

  if (state->input.item_slot_input.item1) {
    player->weapon = player->weapon_inv[0];
    slot_inv_select(player->inventory_ui, 0);
  } else if (state->input.item_slot_input.item2) {
    player->weapon = player->weapon_inv[1];
    slot_inv_select(player->inventory_ui, 1);
  } else if (state->input.item_slot_input.item3) {
    player->weapon = player->weapon_inv[2];
    slot_inv_select(player->inventory_ui, 2);
  } else if (state->input.item_slot_input.item4) {
    player->weapon = player->weapon_inv[3];
    slot_inv_select(player->inventory_ui, 3);
  }

  if (state->input.map) {
    if (player->ui_map->isShowing)
      ui_map_hide(player->ui_map, state);
    else
      ui_map_show(player->ui_map, state);
  }

  player->look_dir = vector2_normalize(
      vector2_sub(state->input.mouse_pos,
                  world_to_screen_pos(&state->camera, player->go->position)));

  player->weapon->go->position = player->go->position;

  if (state->input.mouse_held == 1) {
    player->weapon->fire(player->weapon->binding, state);
  }

  state->camera.position = player->go->position;
}

static void render(void *self, GameState *state) {
  Player *player = (Player *)self;
  SDL_Rect c_rect;
  c_rect.w = 32 * 3;
  c_rect.h = 34 * 3;

  Vector2 render_pos = world_to_screen_pos(
      &state->camera, (Vector2){player->go->position.x - c_rect.w / 2.0,
                               player->go->position.y - c_rect.h / 2.0});

  c_rect.x = render_pos.x;
  c_rect.y = render_pos.y;

  SDL_Rect h_rect;

  h_rect.w = 32 * 3;
  h_rect.h = 34 * 3;

  h_rect.x = render_pos.x;
  h_rect.y = render_pos.y - 6 * 3;

  SDL_RenderCopyEx(state->renderer,
                   player->look_dir.y >= 0 ? player->c_f_tex : player->c_f_tex,
                   NULL, &c_rect, 0.0f, NULL,
                   player->look_dir.x >= 0 ? SDL_FLIP_NONE
                                           : SDL_FLIP_HORIZONTAL);
}
