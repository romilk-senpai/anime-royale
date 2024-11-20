#include "ui_inventory.h"
#include "../../sdl_helper.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include <string.h>

InventoryUI *inventory_ui_new(GameState *state, size_t slot_count,
                              Weapon **weapon_inv) {
  InventoryUI *ui = malloc(sizeof(InventoryUI));
  ui->slot_count = slot_count;
  ui->selected_item = 0;
  ui->weapon_inv = weapon_inv;
  ui->slots = malloc(sizeof(InventorySlotUI) * slot_count);
  for (size_t i = 0; i < slot_count; i++) {
    *(ui->slots + i) = (InventorySlotUI){
        .bg_tex = create_sdl_texture(state->renderer, "assets/inv_slot.png"),
        .fg_tex = weapon_inv[i]->icon_tex,
        .highlighted = 0};
  }

  ui->slots->highlighted = 1;

  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), ui, update, render);
  ui->go = go;
  go->z_index = 100;

  go_pool_bind(state->go_pool, go);

  return ui;
}

void slot_inv_select(InventoryUI *ui, size_t item) {
  ui->slots[ui->selected_item].highlighted = 0;
  ui->slots[item].highlighted = 1;
  ui->selected_item = item;
}

static void update(GameState *state, void *context) {}

static void render(GameState *state, void *context) {
  InventoryUI *ui = (InventoryUI *)context;
  int spacing = 14;
  int item_width = 64;
  int item_height = 64;
  int total_width = ui->slot_count * (item_width + spacing) - spacing;
  int start_x = (state->camera->viewbox.x - total_width) / 2.0f;
  int start_y = state->camera->viewbox.y - item_height - 24;
  for (size_t i = 0; i < ui->slot_count; i++) {
    InventorySlotUI *slot = ui->slots + i;
    SDL_Rect bg_rect = {start_x + i * (item_width + spacing), start_y,
                        item_height, item_height};
    if (slot->highlighted) {
      SDL_SetTextureAlphaMod(slot->bg_tex, 255);
    } else {
      SDL_SetTextureAlphaMod(slot->bg_tex, 150);
    }
    SDL_RenderCopy(state->renderer, slot->bg_tex, NULL, &bg_rect);
    if (slot->bg_tex != NULL) {
      SDL_Rect fg_rect;
      fg_rect.w = 48;
      fg_rect.h = 48;
      fg_rect.x = bg_rect.x + item_width / 2 - fg_rect.w / 2;
      fg_rect.y = bg_rect.y + item_height / 2 - fg_rect.h / 2;
      SDL_RenderCopy(state->renderer, slot->fg_tex, NULL, &fg_rect);
    }
  }
}
