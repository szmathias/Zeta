//
// Created by zack on 10/8/25.
//

#ifndef ZETA_CLAY_SDL_RENDERER_H
#define ZETA_CLAY_SDL_RENDERER_H

#ifndef CLAY_IMPLEMENTATION
#include "clay.h"
#endif

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

typedef struct {
    SDL_Renderer *renderer;
    TTF_TextEngine *textEngine;
    TTF_Font **fonts;
} Clay_SDL3RendererData;

#define NUM_CIRCLE_SEGMENTS 16

void SDL_Clay_RenderFillRoundedRect(Clay_SDL3RendererData *rendererData, SDL_FRect rect, float cornerRadius, Clay_Color _color);
void SDL_Clay_RenderArc(const Clay_SDL3RendererData *rendererData, SDL_FPoint center, float radius, float startAngle, float endAngle, float thickness, Clay_Color color);
void SDL_Clay_RenderClayCommands(Clay_SDL3RendererData *rendererData, Clay_RenderCommandArray *rcommands);


#endif //ZETA_CLAY_SDL_RENDERER_H