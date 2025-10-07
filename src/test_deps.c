#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

#include "anvil/common.h"
#include "anvil/containers/arraylist.h"

#define WINDOW_TITLE "Test"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


int main(void) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "ERROR: SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window;
    window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_VULKAN);

    if (window == NULL) {
        fprintf(stderr, "ERROR: SDL_CreateWindow failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    bool quit = false;
    while (!quit) {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
            {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    ANVAllocator alloc = anv_alloc_default();
    ANVArrayList *list = anv_arraylist_create(&alloc, 0);

    int nums[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        anv_arraylist_push_back(list, &nums[i]);
    }

    for (int i = 0; i < anv_arraylist_size(list); i++)
    {
        printf("Num: %d\n", *(int*)anv_arraylist_get(list, i));
    }

    anv_arraylist_destroy(list, false);

    printf("Hello, World!\n");

    return 0;
}