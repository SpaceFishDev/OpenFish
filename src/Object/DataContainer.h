#pragma once
#include<iostream>
#include<vector>
#include"../util.h"
class DataContainer{
private:
	void* Data;
public:
	const std::type_info* iType; 
	int TypeID = 0;
	DataContainer(){
	}	
	template<class T>
	DataContainer(T data){
		auto& type = typeid(T);
		iType = &type;
		int i = 0;
		for(const std::type_info* Type : Types)
		{
			if(*Type == type){
				TypeID = i;
				Data = (void*)&data;
				return;
			}
			++i;
		}
		Types.push_back(&type);
		TypeID = i;
	}
	template <class T>
	void operator=(T data){
		if(typeid(data) != *Types[TypeID]){
			std::cout << "Invalid Type";
			exit(-1);
		}
		Data = (void*)&data;
	}
	template<class T>
	bool Equals(T data){
		if(typeid(T) != *Types[TypeID]){
			return false;
		}
		return (T)*Data == data;
	}
	template<class T>
	T* GetData()
	{
		if(typeid(T) == *Types[TypeID]){
			return (T*)Data;
		}
	}
};

