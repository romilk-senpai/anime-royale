#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

SDL_Texture *create_sdl_texture(SDL_Renderer *renderer, char *path) {
  SDL_Surface *surf = IMG_Load(path);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
  SDL_FreeSurface(surf);
  return tex;
}
