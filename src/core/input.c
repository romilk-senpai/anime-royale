#include "input.h"
#include "vector2.h"
#include <stdlib.h>

Input *input_new() {
  Input *i = malloc(sizeof(Input));
  *i = (Input){vector2_zero(), vector2_zero(), 0, 0, 0};
  i->item_slot_input = malloc(sizeof(ItemSoltInput));
  *i->item_slot_input = (ItemSoltInput){0, 0, 0, 0};
  return i;
}
