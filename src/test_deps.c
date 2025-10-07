#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_raylib_renderer.h"

#include "stdio.h"
#include "stdlib.h"

// This function is new since the video was published
void HandleClayErrors(const Clay_ErrorData error_data)
{
    printf("%s", error_data.errorText.chars);
}

int main(void)
{
    const float width = 640.0f;
    const float height = 480.0f;

    Clay_Raylib_Initialize((int)width, (int)height, "Introducing Clay Demo", FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);

    const uint64_t clay_required_memory = Clay_MinMemorySize();
    const Clay_Arena clay_memory = Clay_CreateArenaWithCapacityAndMemory(clay_required_memory, malloc(clay_required_memory));

    Clay_Initialize(clay_memory, (Clay_Dimensions){
                        .width = (float)GetScreenWidth(),
                        .height = (float)GetScreenHeight()
                    }, (Clay_ErrorHandler){HandleClayErrors});

    while (!WindowShouldClose())
    {
        // Run once per frame
        Clay_SetLayoutDimensions((Clay_Dimensions){
            .width = (float)GetScreenWidth(),
            .height = (float)GetScreenHeight()
        });

        const Vector2 mousePosition = GetMousePosition();
        const Vector2 scrollDelta = GetMouseWheelMoveV();
        Clay_SetPointerState(
            (Clay_Vector2){mousePosition.x, mousePosition.y},
            IsMouseButtonDown(0)
        );

        Clay_UpdateScrollContainers(
            true,
            (Clay_Vector2){scrollDelta.x, scrollDelta.y},
            GetFrameTime()
        );

        Clay_BeginLayout();


        const Clay_RenderCommandArray renderCommands = Clay_EndLayout();

        BeginDrawing();

        ClearBackground(BLACK);
        Clay_Raylib_Render(renderCommands, NULL);

        EndDrawing();
    }

    Clay_Raylib_Close();
}
