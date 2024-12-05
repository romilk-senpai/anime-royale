#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <sys/types.h>

SDL_Texture *create_sdl_texture(SDL_Renderer *renderer, char *path) {
  SDL_Surface *surf = IMG_Load(path);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
  SDL_FreeSurface(surf);
  return tex;
}

SDL_Texture *create_sdl_text(SDL_Renderer *renderer, TTF_Font *font, char *text,
                             SDL_Color text_color) {
  SDL_Surface *text_surf = TTF_RenderText_Blended(font, text, text_color);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, text_surf);
  SDL_FreeSurface(text_surf);
  return tex;
}
