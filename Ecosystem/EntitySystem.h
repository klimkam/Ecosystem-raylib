#pragma once
#include "Plant.h"
#include "Rabbit.h"
#include "Fox.h"
#include <list>
#include <iterator>
#include <cmath>

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
	EntitySystem() {};
	EntitySystem(int minStartEntityCount, int maxStartEntityCount, int minimalEntityCount, int regenerateEntityCount, Texture2D* textureAtlas);
	void Start();
	void Update();
	T* GetRandomEntity();
	T* ClosestToThePoint(Entity* fromEntity);
	void KillEntity(T* entity);

	void ClearTargets(Entity* target);

private:
	void GenerateEntities();
	void RegenerateEntities();
};

