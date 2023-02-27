
#include<iostream>
#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>
#include<vector>



using namespace std;
#define HEIGHT_MAIN_OBJECT 80
#define WIDTH_MAIN_OBJECT 64

#define HEIGHT_MAIN_LASER 5
#define WIDTH_MAIN_LASER 35




enum AmmoType {
    non = 0,
    LASER = 1,
    SPHERE = 2,
};

SDL_Window* g_window;
SDL_Renderer* g_renderer;
SDL_Texture* g_texture;
SDL_Surface* plane;
SDL_Surface* bg;

void LoadImg(SDL_Surface* var_name, string file_path)
{
    var_name = IMG_Load(file_path.c_str());
}
void RenderAndTex()
{

    g_window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, 0);
    g_renderer = SDL_CreateRenderer(g_window, -1, 0);
    g_texture = SDL_CreateTextureFromSurface(g_renderer, bg);
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







void AmmoObject(int x, int y, int w, int h)
{
    SDL_Rect AmmoRect;
    AmmoRect.x = x;
    AmmoRect.y = y;
    AmmoRect.w = w;
    AmmoRect.h = h;
    int ammo_type;

    // nhớ thêm hàm return ammo_type
}


void setType()
{

}


void HandleMoveAmmo()
{

}

void HandleInputActionAmmo(SDL_Event e)
{

}
void SetAmoList()
{

}








int main(int argc, char* argv[])
{
    int rect_x = 500;
    int rect_y = 320;
    int width_o = 80;
    int height_o = 64;

    SDL_Surface* ammo = NULL;
    SDL_Surface* ammo2 = NULL;

    bool quit = false;
    SDL_Event g_event;

    SDL_Init(SDL_INIT_VIDEO);
    g_window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, 0);
    g_renderer = SDL_CreateRenderer(g_window, -1, 0);

    bg = IMG_Load("bg2.png");
    SDL_Surface* human = IMG_Load("human64x91.png");

    plane = IMG_Load("plane80.png");

    SDL_SetColorKey(plane, SDL_TRUE, SDL_MapRGB(plane->format, 0, 0xFF, 0xFF));

    SDL_Rect  plane_rect;
    plane_rect.x = 200;
    plane_rect.y = 200;
    plane_rect.w = width_o;
    plane_rect.h = height_o;

    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(g_renderer, plane);
    g_texture = SDL_CreateTextureFromSurface(g_renderer, bg);

    ammo = IMG_Load("laser.png");
    SDL_Texture* texture3 = SDL_CreateTextureFromSurface(g_renderer, ammo);




    SDL_Rect AmmoRect;
    AmmoRect.x = plane_rect.x + 80;
    AmmoRect.y = plane_rect.y + 32;
    AmmoRect.w = WIDTH_MAIN_LASER;
    AmmoRect.h = HEIGHT_MAIN_LASER;
    vector <SDL_Rect> ammo_rect;
    ammo_rect.push_back(AmmoRect);
    while (!quit)
    {
        SDL_WaitEvent(&g_event);
        if (g_event.type == SDL_KEYDOWN)


        {
            switch (g_event.key.keysym.sym)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDLK_UP:
                if ((plane_rect.y < 600) || (plane_rect.y > 0))
                {
                    plane_rect.y -= height_o;
                }

                /*AmmoRect.x = plane_rect.x + 80;
                AmmoRect.y = plane_rect.y + 23;*/
                break;
            case SDLK_DOWN:
                if ((plane_rect.y < 600) && (plane_rect.y > 0))
                {
                    plane_rect.y += height_o / 4;
                }

                /*AmmoRect.x = plane_rect.x + 80;
                AmmoRect.y = plane_rect.y + 23;*/

                break;
            case SDLK_RIGHT:

                if ((plane_rect.x < 1200) && (plane_rect.x > 0))
                {
                    plane_rect.x += width_o / 4;
                }

                /*AmmoRect.x = plane_rect.x + 80;
                AmmoRect.y = plane_rect.y + 23;*/
                break;
            case SDLK_LEFT:
                if ((plane_rect.x < 1200) && (plane_rect.x > 0))
                {
                    plane_rect.x -= width_o / 4;
                }

                /*AmmoRect.x = plane_rect.x + 80;
                AmmoRect.y = plane_rect.y + 23;*/
                break;
            }
        }

        else if (g_event.type == SDL_KEYUP)
        {
            switch (g_event.key.keysym.sym)
            {
                /*case SDLK_UP:
                    plane_rect.y += height_o ;*/
            }
        }
        else if (g_event.type == SDL_MOUSEBUTTONDOWN)
        {

            if (g_event.button.button == SDL_BUTTON_LEFT)
            {

                AmmoRect.w = WIDTH_MAIN_LASER;
                AmmoRect.h = HEIGHT_MAIN_LASER;

                AmmoRect.x += 80;

                ammo_rect.push_back(AmmoRect);


                /* if (g_event.button.button == SDL_BUTTON_LEFT)
                 {
                     AmmoRect.x = AmmoRect.x + 80;
                     AmmoRect.y = AmmoRect.x + 23;
                     AmmoRect.w = WIDTH_MAIN_LASER;
                     AmmoRect.h = HEIGHT_MAIN_LASER;
                     AmmoRect.x += 20;
                 }*/



            }
        }

        else if (g_event.type == SDL_MOUSEBUTTONUP)
        {
            ;
        }



        /*SDL_BlitSurface(plane, NULL, bg, &plane_rect);*/
        SDL_RenderCopy(g_renderer, g_texture, NULL, NULL);

        ///*for (int i = 0; i < ammo_rect.size(); i++)*/
        int s = ammo_rect.size();
        for (int k = 0; k < s; k++)
        {
            SDL_RenderCopy(g_renderer, texture3, NULL, &ammo_rect[s - 1]);
        }


        SDL_RenderCopy(g_renderer, texture2, NULL, &plane_rect);

        SDL_RenderPresent(g_renderer);




    }
    destroy();
    SDL_Quit();

    return 0;
}