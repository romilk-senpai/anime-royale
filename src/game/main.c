#include "cursor.h"
#include "player.h"
#include <game.h>

int main(int argc, char *args[]) {
  GameState *state = init_game();

  Player *player = player_new(state);
  Cursor *cursor = cursor_new(state);

  game_run(state);
}
