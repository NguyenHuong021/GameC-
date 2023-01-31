#pragma once
#ifndef COMMONFUNC_H_
#define COMMONFUNC_H_

#include<iostream>
#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>


const int sc_w = 1200;
const int sc_h = 600;
const int sc_bpp = 32;


static SDL_Window* g_window;
static SDL_Renderer* g_renderer;
static SDL_Texture* g_texture;
static SDL_Surface* bg;
static SDL_Event* g_event;

namespace SDLCommonFunction
{
	void LoadImg(std:: string file_path);
	void RenderAndTex();
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y, int w, int h);
	void destroy();
	void ShowWindow();
}



#endif // COMMONFUNC_H_
