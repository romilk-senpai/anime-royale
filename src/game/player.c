#include "player.h"
#include "weapons/pistol.h"
#include "weapons/shotgun.h"
#include "weapons/weapon.h"
#include <SDL2/SDL_render.h>
#include <game.h>
#include <gameobject.h>
#include <stdlib.h>
#include <vector2.h>

Player *player_new(GameState *state) {
  Player *player = malloc(sizeof(Player));

  GameObject *go = go_create(go_pool_new_id(state->go_pool), player,
                             player_update, player_render);
  player->go = go;

  Pistol *pistol = pistol_new(state);
  Shotgun *shotgun = shotgun_new(state);

  player->weapon_inv = malloc(sizeof(Weapon) * 4);

  player->weapon_inv[0] = pistol->weapon;
  player->weapon_inv[1] = shotgun->weapon;

  player->weapon = player->weapon_inv[0];

  go_pool_bind(state->go_pool, go);

  return player;
}

static void player_update(GameState *state, void *context) {
  Player *player = (Player *)context;
  Vector2 movement = vector2_mul_scalar(state->input->movement, 350.0);
  movement = vector2_mul_scalar(movement, state->time->delta_time);
  player->go->position = vector2_add(player->go->position, movement);

  if (state->input->item_slot_input->item1 == 1) {
    player->weapon = player->weapon_inv[0];
  } else if (state->input->item_slot_input->item2 == 1) {
    player->weapon = player->weapon_inv[1];
  }

  player->weapon->go->position = player->go->position;

  if (state->input->fire == 1) {
    player->weapon->fire(state, player->weapon->binding);
  }
}

static void player_render(GameState *state, void *context) {
  Player *player = (Player *)context;
  SDL_Rect rect;
  rect.w = 50;
  rect.h = 50;
  rect.x = player->go->position.x - rect.w / 2.0;
  rect.y = player->go->position.y - rect.h / 2.0;
  SDL_SetRenderDrawColor(state->renderer, 0, 255, 0, 255);
  SDL_RenderFillRect(state->renderer, &rect);
}
