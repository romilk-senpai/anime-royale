#include "core/game.h"

int main(int argc, char *args[]) {
  GameState *state = init_game();
  while (state->quit == 0) {
    handle_time(state);
    process_input(state);
    if (state->quit == 1) {
      break;
    }

    update(state);
    render(state);
  }
  quit(state);
}
