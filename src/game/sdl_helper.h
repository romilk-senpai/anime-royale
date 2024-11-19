#ifndef SDL_WRAPPER_H
#define SDL_WRAPPER_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

typedef struct {

} SDLHelper;

SDL_Texture *create_sdl_texture(SDL_Renderer *renderer, char *path);
SDL_Texture *create_sdl_text(SDL_Renderer *renderer, TTF_Font *font, char *text,
                             SDL_Color text_color);

#endif
