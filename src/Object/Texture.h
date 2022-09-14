
#pragma once
#include<iostream>
#include<vector>
#include "../window/window.h"
#include "../Util.h"
SDL_Color GetPixelColor( SDL_Surface* pSurface,  int X,  int Y);
Color getPixel(Vector2 Position, SDL_Surface* gSurface);



class Texture{
	private:
		std::vector<Pixel> m_Pixels;
	public:
		int Width = 0;
		int Height = 0;
		Texture(){
			#ifndef IMG_INIT_COMPLETE
				#define IMG_INIT_COMPLETE
				IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
			#endif
		}
		Texture(const char* Path){
			#ifndef IMG_INIT_COMPLETE
				#define IMG_INIT_COMPLETE
				IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
			#endif
			SDL_Surface* surface = IMG_Load(Path);
			if(surface == NULL){
				std::cout << "Image could not be loaded: " << Path << "\n";
				exit(-1);
			}
			int width = surface->w;
			int height = surface->h;
			int y = 0;
			while(y != height){
				int x = 0;
				while(x != width){
					Color c = getPixel({x,y}, surface);
					m_Pixels.push_back(Pixel(x,y,c.r,c.g,c.b,c.a));
					++x;
				}
				++y;
			}
			SDL_FreeSurface(surface);
			Width = width;
			Height = height;
		}
		
		Pixel& GetPixel(int x, int y){
			return m_Pixels[x + (y * Width)];
		}
};
