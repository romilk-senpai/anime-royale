#include "player.h"
#include "camera.h"
#include "weapons/pistol.h"
#include "weapons/shotgun.h"
#include "weapons/weapon.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <game.h>
#include <gameobject.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector2.h>

Player *player_new(GameState *state) {
  Player *player = malloc(sizeof(Player));

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), player, update, render);
  player->go = go;

  Pistol *pistol = pistol_new(state);
  Shotgun *shotgun = shotgun_new(state);

  player->weapon_inv = malloc(sizeof(Weapon) * 4);
  player->weapon_inv[0] = pistol->weapon;
  player->weapon_inv[1] = shotgun->weapon;

  player->weapon = player->weapon_inv[0];

  SDL_Surface *c_f_surf = IMG_Load("assets/c_front.png");
  SDL_Surface *h_f_surf = IMG_Load("assets/h_front.png");
  SDL_Surface *c_b_surf = IMG_Load("assets/c_back.png");
  SDL_Surface *h_b_surf = IMG_Load("assets/h_back.png");
  player->c_f_tex = SDL_CreateTextureFromSurface(state->renderer, c_f_surf);
  player->h_f_tex = SDL_CreateTextureFromSurface(state->renderer, h_f_surf);
  player->c_b_tex = SDL_CreateTextureFromSurface(state->renderer, c_b_surf);
  player->h_b_tex = SDL_CreateTextureFromSurface(state->renderer, h_b_surf);
  SDL_FreeSurface(c_f_surf);
  SDL_FreeSurface(h_f_surf);
  SDL_FreeSurface(c_b_surf);
  SDL_FreeSurface(h_b_surf);

  go_pool_bind(state->go_pool, go);

  return player;
}

static void update(GameState *state, void *context) {
  Player *player = (Player *)context;
  Vector2 movement = vector2_mul_scalar(state->input->movement, 350.0);
  movement = vector2_mul_scalar(movement, state->time->delta_time);
  player->go->position = vector2_add(player->go->position, movement);

  if (state->input->item_slot_input->item1 == 1) {
    player->weapon = player->weapon_inv[0];
  } else if (state->input->item_slot_input->item2 == 1) {
    player->weapon = player->weapon_inv[1];
  }

  player->look_dir = vector2_normalize(
      vector2_sub(state->input->mouse_pos,
                  world_to_screen_pos(state->camera, player->go->position)));

  player->weapon->go->position = player->go->position;

  if (state->input->fire == 1) {
    player->weapon->fire(state, player->weapon->binding);
  }

  state->camera->position = player->go->position;
}

static void render(GameState *state, void *context) {
  Player *player = (Player *)context;
  SDL_Rect c_rect;
  c_rect.w = 32 * 3;
  c_rect.h = 34 * 3;

  Vector2 render_pos = world_to_screen_pos(
      state->camera, (Vector2){player->go->position.x - c_rect.w / 2.0,
                               player->go->position.y - c_rect.h / 2.0});

  c_rect.x = render_pos.x;
  c_rect.y = render_pos.y;

  SDL_Rect h_rect;

  h_rect.w = 32 * 3;
  h_rect.h = 34 * 3;

  h_rect.x = render_pos.x;
  h_rect.y = render_pos.y - 6 * 3;

  SDL_RenderCopyEx(state->renderer,
                   player->look_dir.y >= 0 ? player->c_f_tex : player->c_b_tex,
                   NULL, &c_rect, 0.0f, NULL,
                   player->look_dir.x >= 0 ? SDL_FLIP_NONE
                                           : SDL_FLIP_HORIZONTAL);
  SDL_RenderCopyEx(state->renderer,
                   player->look_dir.y >= 0 ? player->h_f_tex : player->h_b_tex,
                   NULL, &h_rect, 0.0f, NULL,
                   player->look_dir.x >= 0 ? SDL_FLIP_NONE
                                           : SDL_FLIP_HORIZONTAL);

  SDL_Rect rect;
  rect.w = 50;
  rect.h = 50;
  Vector2 square_pos = world_to_screen_pos(state->camera, vector2_zero());
  rect.x = square_pos.x;
  rect.y = square_pos.y;

  SDL_SetRenderDrawColor(state->renderer,
                         (int)((sin(state->time->time) + 1) * 127), 0, 0, 255);
  SDL_RenderFillRect(state->renderer, &rect);
}
