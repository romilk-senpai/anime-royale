#ifndef PLAYER_H
#define PLAYER_H

#include "ui/ui_inventory.h"
#include "ui/ui_map.h"
#include "vector2.h"
#include "weapons/weapon.h"
#include <SDL2/SDL_render.h>
#include <game.h>
#include <gameobject.h>

typedef struct {
  GameObject *go;
  Weapon **weapon_inv;
  Weapon *weapon;
  InventoryUI *inventory_ui;
  UIMap *ui_map;
  Vector2 look_dir;
  Vector2 movement;
  CelestialBody *celestial_body;
  SDL_Texture *c_f_tex;
  SDL_Texture *h_f_tex;
  SDL_Texture *c_b_tex;
  SDL_Texture *h_b_tex;
} Player;

Player *player_new(GameState *state);
static void update(GameState *state, void *context);
static void render(GameState *state, void *context);

#endif
