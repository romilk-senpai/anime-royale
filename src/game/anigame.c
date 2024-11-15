#include "anigame.h"
#include "gameobjects/bg_renderer.h"
#include "gameobjects/cursor.h"
#include "gameobjects/player.h"
#include <stdlib.h>

AniGame *anigame_new(GameState *state) {
  AniGame *anigame = malloc(sizeof(AniGame));
  anigame->player = player_new(state);
  anigame->cursor = cursor_new(state);
  anigame->bg_renderer = bg_renderer_new(state);
  return anigame;
}
