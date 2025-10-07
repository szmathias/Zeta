//
// Created by zack on 10/7/25.
//

#ifndef ZETA_CLAY_RAYLIB_RENDERER_H
#define ZETA_CLAY_RAYLIB_RENDERER_H

#ifndef CLAY_IMPLEMENTATION
#include "clay.h"
#endif

#include "raylib.h"
#include "raymath.h"

#ifdef __cplusplus
extern "C" {
#endif


#define CLAY_RECTANGLE_TO_RAYLIB_RECTANGLE(rectangle) (Rectangle) { .x = rectangle.x, .y = rectangle.y, .width = rectangle.width, .height = rectangle.height }
#define CLAY_COLOR_TO_RAYLIB_COLOR(color) (Color) { .r = (unsigned char)roundf(color.r), .g = (unsigned char)roundf(color.g), .b = (unsigned char)roundf(color.b), .a = (unsigned char)roundf(color.a) }

Ray GetScreenToWorldPointWithZDistance(Vector2 position, Camera camera, int screenWidth, int screenHeight, float zDistance);

Clay_Dimensions Raylib_MeasureText(Clay_StringSlice text, Clay_TextElementConfig* config, void* userData);

void Clay_Raylib_Initialize(int width, int height, const char* title, unsigned int flags);
void Clay_Raylib_Close(void);

void Clay_Raylib_Render(Clay_RenderCommandArray renderCommands, const Font* fonts);





#ifdef __cplusplus
}
#endif

#endif //ZETA_CLAY_RAYLIB_RENDERER_H