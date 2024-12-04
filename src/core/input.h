#ifndef INPUT_H
#define INPUT_H

#include "vector2.h"

typedef struct {
  int item1;
  int item2;
  int item3;
  int item4;
} ItemSoltInput;

typedef struct {
  Vector2 movement;
  Vector2 mouse_pos;
  int mouse_held;
  int mouse_down;
  int map;
  int quit;
  ItemSoltInput item_slot_input;
} Input;

void input_update(Input *self);

#endif
