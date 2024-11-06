#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "game.h"

typedef void (*update_go)(GameState *);
typedef void (*render_go)(GameState *);

typedef struct {
  update_go update;
  render_go render;
} GameObject;

#endif
