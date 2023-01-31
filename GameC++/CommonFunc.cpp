#include"CommonFunc.h"

void SDLCommonFunction:: ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y, int w, int h)
{
    SDL_Rect char_rect;
    char_rect.x = x;
    char_rect.y = y;
    char_rect.w = w;
    char_rect.h = h;
    SDL_BlitSurface(src, NULL, des, &char_rect);
}


void SDLCommonFunction::LoadImg(std::string file_path)
{
    bg = IMG_Load(file_path.c_str());
}

void RenderAndTex()
{
    g_window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sc_w, sc_h, 0);
    g_renderer = SDL_CreateRenderer(g_window, -1, 0);
    g_texture = SDL_CreateTextureFromSurface(g_renderer, bg);
}

void SDLCommonFunction::destroy()
{
    SDL_DestroyTexture(g_texture);
    SDL_FreeSurface(bg);
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
}