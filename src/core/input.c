#include "input.h"
#include "vector2.h"
#include <SDL2/SDL_events.h>

void input_update(Input *self) {
  self->mouse_held = 0;
  self->mouse_down = 0;
  self->map = 0;
  self->quit = 0;
  self->item_slot_input = (ItemSoltInput){};

  SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    switch (e.type) {
    case SDL_QUIT:
      self->quit = 1;
      return;

    case SDL_WINDOWEVENT:
      if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
        break;
      }
    case SDL_MOUSEMOTION:
      self->mouse_pos = (Vector2){e.motion.x, e.motion.y};
      break;

    case SDL_KEYDOWN:
      switch (e.key.keysym.sym) {
      case SDLK_1:
        self->item_slot_input.item1 = 1;
        break;
      case SDLK_2:
        self->item_slot_input.item2 = 1;
        break;
      case SDLK_3:
        self->item_slot_input.item3 = 1;
        break;
      case SDLK_4:
        self->item_slot_input.item4 = 1;
        break;
      case SDLK_TAB:
        self->map = 1;
        break;
      }
    case SDL_MOUSEBUTTONDOWN:
      if (e.button.button == SDL_BUTTON_LEFT) {
        self->mouse_down = 1;
      }
      break;
    }
  }

  const Uint8 *keystate = SDL_GetKeyboardState(NULL);
  Vector2 in_move = vector2_zero();
  if (keystate[SDL_SCANCODE_W]) {
    in_move.y--;
  }
  if (keystate[SDL_SCANCODE_S]) {
    in_move.y++;
  }
  if (keystate[SDL_SCANCODE_A]) {
    in_move.x--;
  }
  if (keystate[SDL_SCANCODE_D]) {
    in_move.x++;
  }

  int mouses_x, mouses_y;
  Uint32 mousestate = SDL_GetRelativeMouseState(&mouses_x, &mouses_y);
  self->mouse_held = mousestate & SDL_BUTTON(SDL_BUTTON_LEFT);
  self->movement = vector2_normalize(in_move);
}
