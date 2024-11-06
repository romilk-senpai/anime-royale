#include "core/game.h"

int main(int argc, char *args[]) {
  GameState *state = init_game();
  while (state->quit == 0) {
    process_input(state);
    if (state->quit) {
      break;
    }

    update(state);
    render(state);
  }
  quit(state);
}
