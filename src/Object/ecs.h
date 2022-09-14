#pragma once
#include "DataContainer.h"
/*
	very simple entity component system implimentation.
*/


class Component{
private:
	DataContainer m_Data;
public:
	int ID = 0;
	const char* Title;
	Component()
	{
		Title = "";
	}
	template <class T>
	Component(T data, const char* title){
		m_Data = DataContainer(data);
		Title = title;
		while(*title != '\0'){
			ID += *Title; // Generate an ID I don't wanna do random so I did this.
			++title;
		}
	}
	DataContainer& GetData(){
		return m_Data;
	}
};

class ComponentPool{
private:
	static std::vector<Component> components;
public:
	static Component* GetComponent(int ID){
		for(auto& Comp : components ){
			if(ID == Comp.ID){
				return &Comp;
			}
		}
		return nullptr;
	}
	static Component* GetComponentFromTitle(const char* t){
		for(auto& Comp : components ){
			if(t == Comp.Title){
				return &Comp;
			}
		}
		return nullptr;
	}
	static void AddComponent(Component component){
		components.push_back(component);
	}

};

class Entity{
private:
	std::vector<Component> m_Components;
public:
	void AddComponent(Component component){
		m_Components.push_back(component);
	}
	Component* GetComponent(const char* Title){
		for(Component& component : m_Components){
			if(component.Title == Title){
				return &component;
			}
		}
		return nullptr; // Doesnt exist.
	}

};
class System{
private:
	void (*m_CallBack)(Entity*);
public:
	void SetCallBack(void (*CallBack)(Entity*)){
		m_CallBack = CallBack;
	}
	void Call(Entity* CallEntity){
		m_CallBack	(CallEntity);
	}
}; 