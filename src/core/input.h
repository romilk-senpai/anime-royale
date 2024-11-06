#ifndef INPUT_H
#define INPUT_H

#include "vector2.h"

typedef struct {
  Vector2 movement;
} Input;

Input *input_new();

#endif
