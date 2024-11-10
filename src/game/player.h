#ifndef PLAYER_H
#define PLAYER_H

#include "weapons/weapon.h"
#include <gameobject.h>
#include <game.h>

typedef struct {
	GameObject *go;
	Weapon *weapon;
} Player;

Player *player_new(GameState *state);
static void player_update(GameState *state, void *context);
static void player_render(GameState *state, void *context);

#endif
