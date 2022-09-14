#include "OpenFish.h" 
#include<iostream>
/*

	Example of rendering an image , it looks obtuse, but it will speed up tasks when the project gets bigger.

*/
void Update(Entity* obj){
	Component* Pos = obj->GetComponent("Position");
	if(Pos == nullptr){
		return;
	}
	Component* Sprite = obj->GetComponent("Sprite");
	if(Sprite == nullptr){
		return;
	}
	Component* Rend = obj->GetComponent("Renderer");
	if(Rend == nullptr){
		return;
	}
	Component* Wind = obj->GetComponent("Window");
	if(Wind == nullptr){
		return;
	}
	DataContainer dTex = Sprite->GetData();
	Texture* TexPtr = dTex.GetData<Texture>();
	Renderer* renderer = Rend->GetData().GetData<Renderer>();
	const char** window = Wind->GetData().GetData<const char*>();
	renderer->DrawTexture(*window, *TexPtr, *Pos->GetData().GetData<Vector2>());
}

int main()
{
	Renderer r = Renderer(500,500, "Hello, Renderer!");
	Entity TestObject;
	TestObject.AddComponent(Component( Texture("test.png"), "Sprite"));
	TestObject.AddComponent(Component( Vector2(0,0), "Position"));
	TestObject.AddComponent(Component( &r, "Renderer"));
	TestObject.AddComponent(Component("Hello, Renderer!", "Window"));
	System UpdateObject;
	UpdateObject.SetCallBack(Update);
	while(r.Running){
		UpdateObject.Call(&TestObject);
		r.Update();
	}	
	return 0;
}
