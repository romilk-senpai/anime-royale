#include "core/game.h"

int main(int argc, char *args[]) {
  GameState *state = init_game();
  while (state->quit == 0) {
    handle_time(state);
    process_input(state);
    if (state->quit == 1) {
      break;
    }

    update_game(state);
    render_game(state);
  }
  quit_game(state);
}
