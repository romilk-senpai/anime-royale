#include "input.h"
#include <stdlib.h>

Input *input_new() {
  Input *i = malloc(sizeof(Input));
  *i = (Input){vector2_zero()};
  return i;
}
