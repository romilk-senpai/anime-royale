#include "anigame.h"
#include "gameobjects/bg_renderer.h"
#include "gameobjects/cursor.h"
#include "gameobjects/gravity_sim.h"
#include "gameobjects/level_layout.h"
#include "gameobjects/player.h"
#include "gameobjects/ui/ui_map.h"
#include <stdlib.h>

AniGame *anigame_new(GameState *state) {
  AniGame *anigame = malloc(sizeof(AniGame));
  anigame->player = player_new(state);
  anigame->cursor = cursor_new(state);
  anigame->bg_renderer = bg_renderer_new(state);
  anigame->inventory_ui =
      inventory_ui_new(state, 4, anigame->player->weapon_inv);
  anigame->level_layout = level_layout_new(state);
  level_layout_fill_basic(anigame->level_layout, state);
  anigame->gravity_sim =
      gravity_sim_new(state, anigame->player, anigame->level_layout);
  anigame->ui_map =
      ui_map_new(state, &anigame->player->go->position, anigame->level_layout);
  anigame->player->inventory_ui = anigame->inventory_ui;
  anigame->player->ui_map = anigame->ui_map;
  return anigame;
}
