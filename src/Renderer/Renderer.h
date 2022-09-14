#pragma once
#include<vector>
#define SDL_MAIN_HANDLED
static std::vector<const std::type_info*> Types;
#include"../object/ecs.h"
#include "../window/window.h"
#include "../object/texture.h"
class Renderer{

	private:
		Window m_RootWindow;
		std::vector<Window> m_Windows;
		bool KeyboardLast[512];
	public:
		bool Keyboard[512];
		bool Running = true; 
		Renderer(int width, int height, const char* title);
		void CreateWindow(int width, int height, const char* title);
		Window& GetWindowFromId(int Id);	
		Window& GetWindow(const char* title);
		void DrawTexture(const char* windowTitle, Texture t, Vector2 Position); // Depreciated.
		void Update();
};
