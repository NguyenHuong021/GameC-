
#include<iostream>
#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>


using namespace std;
const int sc_w = 1200;
const int sc_h = 600;
const int sc_bpp = 32;


static SDL_Window* g_window;
static SDL_Renderer* g_renderer;
static SDL_Texture* g_texture;
static SDL_Surface* bg;
static SDL_Event* g_event;


void LoadImg(SDL_Surface*var_name, string file_path)
{
    var_name = IMG_Load(file_path.c_str());
}
void RenderAndTex()
{
    g_window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sc_w, sc_h, 0);
    g_renderer = SDL_CreateRenderer(g_window, -1, 0);
    g_texture = SDL_CreateTextureFromSurface(g_renderer, bg);
}
void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y, int w, int h)
{
    SDL_Rect char_rect;
    char_rect.x = x;
    char_rect.y = y;
    char_rect.w = w;
    char_rect.h = h;
    SDL_BlitSurface(src, NULL, des, &char_rect);
}
void destroy()
{
    SDL_DestroyTexture(g_texture);
    SDL_FreeSurface(bg);
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
}

void ShowWindow()
{
	SDL_RenderCopy(g_renderer, g_texture, NULL, NULL);
	SDL_RenderPresent(g_renderer);
}



// bắt sự kiện bàn phím


void handleMove()
{
}



int main(int argc, char* argv[])
{
    

    bool quit = false;
    SDL_Event event;
  

    SDL_Init(SDL_INIT_VIDEO);
    LoadImg(bg, "bg2.png");
    RenderAndTex();
    
 
    while (!quit)
    {
        SDL_WaitEvent(&event);
        SDL_RenderCopy(g_renderer, g_texture, NULL, NULL);
        SDL_RenderPresent(g_renderer);
    }
    destroy();
    SDL_Quit();
	

    return 0;
}

