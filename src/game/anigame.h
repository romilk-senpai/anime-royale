#ifndef ANIGAME_H
#define ANIGAME_H

#include "game.h"
#include "gameobjects/bg_renderer.h"
#include "gameobjects/cursor.h"
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
  UIMap *ui_map;
} AniGame;

AniGame *anigame_new(GameState *state);

#endif
