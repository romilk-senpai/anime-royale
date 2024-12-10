#include "anicontroller.h"
#include <game.h>

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

int main(int argc, char *args[]) {
  AniController *ar_controller = anicontroller_new();
  GameState *state = init_game(ar_controller->game_controller);

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop_arg(game_run, (void *)state, 0, 1);
#else
  game_run(state);
#endif
}
