#include"renderer.h"


Renderer::Renderer(int width, int height, const char* title){
	SDL_Init(SDL_INIT_EVERYTHING);
	m_RootWindow = Window(width, height, title);
}

void Renderer::CreateWindow(int width, int height, const char* title){
	Window w = Window(width, height, title);
	m_Windows.push_back(w);
}

Window& Renderer::GetWindow(const char* title){
	for(Window& w : m_Windows){
		if(w.Title == title){
			return w;
		}
	}
	return m_RootWindow;
}

Window& Renderer::GetWindowFromId(int id){
	for(Window w : m_Windows){
		if(w.Id == id){
			return w;
		}
	}
	return m_RootWindow;
}

void Renderer::DrawTexture(const char* windowTitle, Texture t, Vector2 Position){
	Window& w = GetWindow(windowTitle);
        int x = 0;
	while(x != t.Width){
		int y = 0;
		while(y != t.Height){
			Pixel p = t.GetPixel(x,y);
			p.Position.x += Position.x;
			p.Position.y += Position.y;
			w.DrawPixel(p);
			++y;
		}	
		++x;
	}
}

void Renderer::Update(){
	m_RootWindow.Redraw();
	if(m_RootWindow.Running != true){
		Running = false;
		SDL_Quit();
	}
	for(Window w : m_Windows){
		if(w.Running){
			w.Redraw();
		}
	}
	int i = 0;
	for(; i != 512; ++i){
		Keyboard[i] = m_RootWindow.Keyboard[i]; 
	}
}
