#include "ui_map.h"
#include "go_pool.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>

UIMap *ui_map_new(GameState *state, Vector2 *player_pos,
                  LevelLayout *level_layout) {
  UIMap *map = malloc(sizeof(UIMap));
  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), map, update, render);
  go->z_index = 101;
  map->level_layout = level_layout;
  map->player_pos = player_pos;
  map->isShowing = 0;
  map->go = go;
  return map;
}

void ui_map_show(UIMap *map, GameState *state) {
  map->isShowing = 1;
  go_pool_bind(state->go_pool, map->go);
}

void ui_map_hide(UIMap *map, GameState *state) {
  map->isShowing = 0;
  go_pool_unbind(state->go_pool, map->go);
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {
  UIMap *map = (UIMap *)context;
  SDL_Rect map_rect_outer;
  map_rect_outer.w = 484;
  map_rect_outer.h = 484;
  map_rect_outer.x = state->camera->viewbox.x / 2.0f - map_rect_outer.w / 2.0f;
  map_rect_outer.y = state->camera->viewbox.y / 2.0f - map_rect_outer.h / 2.0f;
  SDL_SetRenderDrawColor(state->renderer, 200, 200, 200, 255);
  SDL_RenderFillRect(state->renderer, &map_rect_outer);

  SDL_Rect map_rect;
  map_rect.w = 480;
  map_rect.h = 480;
  map_rect.x = state->camera->viewbox.x / 2.0f - map_rect.w / 2.0f;
  map_rect.y = state->camera->viewbox.y / 2.0f - map_rect.h / 2.0f;
  SDL_SetRenderDrawColor(state->renderer, 24, 24, 24, 255);
  SDL_RenderFillRect(state->renderer, &map_rect);

  float map_max_width = 8000.0f;

  for (size_t i = 0; i < map->level_layout->num_planets; i++) {
    Planet *p = map->level_layout->planets[i];
    SDL_Rect planet_rect;
    planet_rect.w = map_rect.w * (p->size.x / map_max_width);
    planet_rect.h = map_rect.h * (p->size.y / map_max_width);
    planet_rect.x = map_rect.w * (p->go->position.x / map_max_width) +
                    map_rect.x + map_rect.w / 2.0f - planet_rect.w / 2.0f;
    planet_rect.y = map_rect.h * (p->go->position.y / map_max_width) +
                    map_rect.y + map_rect.h / 2.0f - planet_rect.h / 2.0f;

    SDL_SetRenderDrawColor(state->renderer, 102, 51, 153, 255);
    SDL_RenderFillRect(state->renderer, &planet_rect);
  }

  Planet *p = map->level_layout->star;
  SDL_Rect star_rect;
  star_rect.w = map_rect.w * (p->size.x / map_max_width);
  star_rect.h = map_rect.h * (p->size.y / map_max_width);
  star_rect.x = map_rect.w * (p->go->position.x / map_max_width) + map_rect.x +
                map_rect.w / 2.0f - star_rect.w / 2.0f;
  star_rect.y = map_rect.h * (p->go->position.y / map_max_width) + map_rect.y +
                map_rect.h / 2.0f - star_rect.h / 2.0f;

  SDL_SetRenderDrawColor(state->renderer, 255, 204, 0, 255);
  SDL_RenderFillRect(state->renderer, &star_rect);

  SDL_Rect player_rect;
  player_rect.w = 4;
  player_rect.h = 4;
  player_rect.x = map_rect.w * (map->player_pos->x / map_max_width) +
                  map_rect.x + map_rect.w / 2.0f - player_rect.w / 2.0f;
  player_rect.y = map_rect.h * (map->player_pos->y / map_max_width) +
                  map_rect.y + map_rect.h / 2.0f - player_rect.h / 2.0f;

  SDL_SetRenderDrawColor(state->renderer, 20, 255, 25, 255);
  SDL_RenderFillRect(state->renderer, &player_rect);
}
