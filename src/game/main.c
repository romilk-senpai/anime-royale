#include "player.h"
#include <game.h>

int main(int argc, char *args[]) {
  GameState *state = init_game();

  Player *player = player_new(state);

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
