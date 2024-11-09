#include "player.h"
#include <SDL2/SDL_render.h>
#include <game.h>
#include <gameobject.h>
#include <stdlib.h>
#include <vector2.h>

Player *player_new(GameState *state) {
  Player *p = malloc(sizeof(Player));

  GameObject *go = malloc(sizeof(GameObject));
  *go = (GameObject){.instance_id = go_pool_new_id(state->go_pool),
                     .binding = p,
                     .position = vector2_zero(),
                     .angle = 0.0,
                     .update = player_update,
                     .render = player_render};
  p->go = go;
  return p;
}

void player_update(GameState *state, void *context) {
  Player *player = (Player *)context;
  Vector2 movement = vector2_mul_scalar(state->input->movement, 350.0);
  movement = vector2_mul_scalar(movement, state->time->delta_time);
  player->go->position = vector2_add(player->go->position, movement);
}

void player_render(GameState *state, void *context) {
  Player *player = (Player *)context;
  SDL_Rect rect;
  rect.x = player->go->position.x;
  rect.y = player->go->position.y;
  rect.w = 50;
  rect.h = 50;
  SDL_SetRenderDrawColor(state->renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(state->renderer, &rect);
}
