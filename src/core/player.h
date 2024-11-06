#ifndef PLAYER_H
#define PLAYER_H

#include "vector2.h"

typedef struct {
	Vector2 position;
	Vector2 movement;
	float angle;
} Player;

Player *new_player();

#endif
