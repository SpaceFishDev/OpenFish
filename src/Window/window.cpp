#include "window.h"

Window::Window(int width, int height, const char* title){
    Width = width;
	Height = height;
	Title = title;
	SDL_CreateWindowAndRenderer(640, 480, 0 , &m_Window, &m_Renderer);
	SDL_SetWindowTitle(m_Window, title);
}

Pixel& Window::GetPixel(Vector2 Position){
	for(Pixel& pixel : m_Pixels){
		if(pixel.Position.x == Position.x){
			if(pixel.Position.y == Position.y)
			{
				return pixel;
			}
		}
	}
}

void Window::Redraw(){
	for(Pixel& pixel : m_Pixels){
		if(pixel.DisplayColor.r != 0 && pixel.DisplayColor.g != 0 && pixel.DisplayColor.b != 0 && pixel.DisplayColor.a != 0){
			SDL_SetRenderDrawColor(m_Renderer, pixel.DisplayColor.r, pixel.DisplayColor.g, pixel.DisplayColor.b, pixel.DisplayColor.a);
			SDL_RenderDrawPoint(m_Renderer, pixel.Position.x, pixel.Position.y);
		}
	}
	SDL_SetRenderDrawColor(m_Renderer, 0,0,0,255);
	SDL_RenderPresent(m_Renderer);
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:{
					      	Running = false;
				     		break;
				      }
			case SDL_WINDOWEVENT:{		
						      	if(event.window.event == SDL_WINDOWEVENT_CLOSE){
								Running = false;
							}
					      		break;
					      }
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				      {	
				      	if(event.key.keysym.sym == SDLK_LSHIFT || event.key.keysym.sym == SDLK_RSHIFT){
					      		Shift = event.type == SDL_KEYDOWN;
						}
						else if(event.key.keysym.sym == SDLK_LCTRL){
							LCntrl = event.type == SDL_KEYDOWN;
						}
						else if(event.key.keysym.sym == SDLK_RCTRL){
							RCntrl = event.type == SDL_KEYDOWN;
						}
						else if(event.key.keysym.sym == SDLK_LALT){
							Alt = event.type == SDL_KEYDOWN;
						}
					    else if(event.key.keysym.sym < 512){
					      	Keyboard[event.key.keysym.sym] = event.type == SDL_KEYDOWN;
					    }
				      		break;
				      }
		}
	}
	SDL_RenderClear(m_Renderer);
}

void Window::DrawPixel(Pixel p){
	m_Pixels.push_back(p);
}









