#ifndef PLAYER_H
#define PLAYER_H

#include <gameobject.h>
#include <game.h>
#include <vector2.h>

typedef struct {
	GameObject *go;
} Player;

Player *player_new(GameState *state);
void player_update(GameState *state, void *context);
void player_render(GameState *state, void *context);

#endif
