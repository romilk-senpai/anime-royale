#include "player.h"
#include <stdlib.h>

Player *new_player() {
  Player *p = malloc(sizeof(Player));
  *p = (Player){vector2_zero(), vector2_zero(), 0};
  return p;
}
