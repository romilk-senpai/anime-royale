#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

SDL_Renderer *renderer;

bool first_pass = true;

void run_main_loop() {
  if (first_pass) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window =
        SDL_CreateWindow("2D Shooter Game", 0, 0, 1280, 720, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    emscripten_set_canvas_size(1280, 720);

    first_pass = false;

    SDL_Surface *surface = IMG_Load("assets/bg_space.png");
  }

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_Rect rect;
  rect.w = 300;
  rect.h = 500;
  rect.y = 720 / 2 - rect.h / 2;
  rect.x = 1280 / 2 - rect.w / 2;
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderFillRect(renderer, &rect);

  SDL_RenderPresent(renderer);
}

int main(int argc, char *args[]) {

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(run_main_loop, 0, true);
#endif

  return 0;
}
