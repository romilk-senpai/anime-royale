#include "player.h"
#include <SDL2/SDL_rect.h>

SDL_Rect player_drawable(Player * p) {
  SDL_Rect rect;
  rect.x = p->position.x;
  rect.y = p->position.y;
  rect.w = 50;
  rect.h = 50;

  return rect;
}
