#pragma once
#include<iostream>

class Exception{
	static void Throw(const char* out){
		std::cout << out << "\n";
		exit(-1);
	}
};

class Color{
	public: 
		int r;
		int g;
		int b;
		int a;
		Color(){
			r = 0;
			g = 0;
			b = 0;
			a = 0;
		}
		
		Color(int r, int g, int b, int a = 255){
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		static Color FromFloatValues(float r, float g, float b, float a){
			return Color((int)r * 255, (int)g * 255, (int)b * 255, (int)a * 255);
		}
		static Color FromHexString(const char* hex){
			int r, g, b;
			if(sscanf(hex, "%02x%02x%02x", &r, &g, &b) == 3){
				return Color(r,g,b,255);
			}
			return Color(0,0,0,255);
		}
		
};

class Vector2{
public:
	float x;
	float y;
	Vector2(){
		x = 0;
		y = 0;
	}
	Vector2(float x, float y){
		this->x = x;
		this->y = y;
	}
	bool operator==(Vector2 p){
		return x == p.x && y == p.y;
	}
	bool operator!=(Vector2 p){
		return !(operator==(p));
	}
};

class Pixel{
public:
	Vector2 Position;
	Color DisplayColor;
	Color& GetColor(){
		return DisplayColor;
	}
	Pixel(){
		Position = Vector2();
		DisplayColor = Color();
	}

	Pixel(float x, float y, float r, float g, float b, float a)
	{	
		Position = Vector2(x,y);
		DisplayColor = Color(r,g,b,a);
	}
	Pixel(Vector2 Pos, Color c){
		Position = Pos;
		DisplayColor = c;
	}
	Pixel(Vector2 Pos, float r, float g, float b, float a){
		Position = Pos;
		DisplayColor = Color(r,g,b,a);
	}
	Pixel(float x, float y, Color c){
		DisplayColor = c;
		Position = Vector2(x,y);
	}
};

	
