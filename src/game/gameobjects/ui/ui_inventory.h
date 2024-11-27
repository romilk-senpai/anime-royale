#ifndef INVENTORY_H
#define INVENTORY_H

#include "../weapons/weapon.h"
#include "game.h"
#include "gameobject.h"
#include <SDL2/SDL_render.h>
#include <stddef.h>

typedef struct {
  SDL_Texture *bg_tex;
  SDL_Texture *fg_tex;
  int highlighted;
} InventorySlotUI;

typedef struct {
  GameObject *go;
  InventorySlotUI *slots;
  Weapon **weapon_inv;
  size_t slot_count;
  size_t selected_item;
} InventoryUI;

InventoryUI *inventory_ui_new(GameState *state, size_t slot_count,
                              Weapon **weapon_inv);
void slot_inv_select(InventoryUI *ui, size_t item);
static void update(void *self, GameState *state);
static void render(void *self, GameState *state);

#endif
