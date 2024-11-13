#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

SDL_Renderer *renderer;

void run_main_loop() {
  SDL_RenderClear(renderer);
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = 100;
  rect.h = 100;

  SDL_SetRenderDrawColor(renderer, 69, 69, 69, 255);
  SDL_RenderDrawRect(renderer, &rect);

  SDL_RenderPresent(renderer);
}

int main(int argc, char *args[]) {

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow("2D Shooter Game", 0, 0, 800, 600, 0);
  renderer = SDL_CreateRenderer(window, -1, 0);

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(run_main_loop, 0, true);
#endif

  return 0;
}
