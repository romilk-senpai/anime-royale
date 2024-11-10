#ifndef PLAYER_H
#define PLAYER_H

#include <gameobject.h>
#include <game.h>

typedef struct {
	GameObject *go;
} Player;

Player *player_new(GameState *state);
static void player_update(GameState *state, void *context);
static void player_render(GameState *state, void *context);

#endif
