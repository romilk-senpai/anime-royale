#ifndef ANIGAME_H
#define ANIGAME_H

#include "game.h"
#include "gameobjects/bg_renderer.h"
#include "gameobjects/cursor.h"
#include "gameobjects/player.h"
#include "gameobjects/ui/ui_inventory.h"

typedef struct {
  Player *player;
  Cursor *cursor;
  BGRenderer *bg_renderer;
  InventoryUI *inventory_ui;
} AniGame;

AniGame *anigame_new(GameState *state);

#endif
