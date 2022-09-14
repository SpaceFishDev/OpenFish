#pragma once
#include<SDL_Image.h>
#include"../util.h"
#include<vector>

class Window{
	private:
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
		std::vector<Pixel> m_Pixels;
		
	public:
		int Id = 0;
		bool Running = true;
		bool Keyboard[512];
		int Width, Height;
		const char* Title;
		bool Shift = false;
		bool Alt = false;
		bool LCntrl = false;
		bool RCntrl = false;
		Window(){
			Width = 0;
			Height = 0;
		}
		Window(int width, int height, const char* title);
		Pixel& GetPixel(Vector2 Position);
		void DrawPixel(Pixel p);
		void Redraw();
};

