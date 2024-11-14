#ifndef SDL_WRAPPER_H
#define SDL_WRAPPER_H

#include <SDL2/SDL_render.h>

typedef struct {

} SDLHelper;

SDL_Texture *create_sdl_texture(SDL_Renderer *renderer, char *path);

#endif
