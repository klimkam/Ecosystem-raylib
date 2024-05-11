#pragma once
#include "Entity.h"
#include "raylib.h"
#include <list>
#include "Plant.h"
#include "Animal.h"
#include "Rabbit.h"
#include "Fox.h"
#include <iostream>

template<class T>
class EntitySystem
{
	std::list<T*> m_entities;

	Texture2D* m_textureAtlas;

	int m_minStartEntityCount = 0;
	int m_maxStartEntityCount = 10;
	int m_startEntityCount = 0;
	
	int m_minimalEntityCount = 5;
	int m_regenerateEntityCount = 7;

public:
	EntitySystem(int minStartEntityCount, int maxStartEntityCount, int minimalEntityCount, int regenerateEntityCount, Texture2D* textureAtlas);
	void Start();
	void Update();

private:
	void GenerateEntities();
	void RegenerateEntities();
	void KillEntity(T* entity);
};

