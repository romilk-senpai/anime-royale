#include "time.h"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

void time_handle(Time *self) {
  Uint32 current_time = SDL_GetTicks();
  float delta_time = (current_time - self->last_time) / 1000.0f;
  self->time = current_time / 1000.0f;
  self->delta_time = delta_time;
  self->last_time = current_time;
}
