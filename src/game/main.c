#include "bg_renderer.h"
#include "cursor.h"
#include "player.h"
#include <game.h>

int main(int argc, char *args[]) {
  GameState *state = init_game(1920, 1080);

  Player *player = player_new(state);
  Cursor *cursor = cursor_new(state);
  BGRenderer *renderer = bg_renderer_new(state);

  game_run(state);
}
