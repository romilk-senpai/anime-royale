#ifndef ANIGAME_H
#define ANIGAME_H

#include "game.h"
#include "gameobjects/bg_renderer.h"
#include "gameobjects/cursor.h"
#include "gameobjects/gravity_sim.h"
#include "gameobjects/level_layout.h"
#include "gameobjects/player.h"
#include "gameobjects/ui/ui_inventory.h"
#include "gameobjects/ui/ui_map.h"

typedef struct {
  Player *player;
  Cursor *cursor;
  BGRenderer *bg_renderer;
  InventoryUI *inventory_ui;
  LevelLayout *level_layout;
  GravitySim *gravity_sim;
  UIMap *ui_map;
} AniGame;

AniGame *anigame_new(GameState *state);

#endif
