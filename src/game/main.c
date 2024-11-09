#include "go_pool.h"
#include "player.h"
#include <game.h>

int main(int argc, char *args[]) {
  GameState *state = init_game();

  Player *player = player_new(state);
  go_pool_bind(state->go_pool, player->go);

  game_run(state);
}
