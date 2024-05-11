#include "EntitySystem.h"
#include<ostream>

template<class T>
EntitySystem<T>::EntitySystem(int minStartEntityCount, int maxStartEntityCount, int minimalEntityCount, int regenerateEntityCount, Texture2D* textureAtlas)
{
	m_minStartEntityCount = minStartEntityCount;
	m_maxStartEntityCount = maxStartEntityCount;
	m_minimalEntityCount = minimalEntityCount;
	m_regenerateEntityCount = regenerateEntityCount;
	m_textureAtlas = textureAtlas;

	Start();
}

template<class T>
void EntitySystem<T>::Start()
{
	GenerateEntities();
}

template<class T>
void EntitySystem<T>::Update()
{
	for (T* entity : m_entities) {
		entity->Update();
	}
}

template<class T>
void EntitySystem<T>::GenerateEntities()
{
	m_startEntityCount = GetRandomValue(m_minStartEntityCount, m_maxStartEntityCount);
	for (int i = 0; i < m_startEntityCount; i++) {
		T* newEntity = new T(m_textureAtlas);
		m_entities.push_back(newEntity);
		std::cout << "Entity id is: " << newEntity->GetId() << std::endl;
	}
}

template<class T>
void EntitySystem<T>::RegenerateEntities()
{
	if (m_entities.size() > m_minimalEntityCount) { return; }

	for (int i = 0; i < m_regenerateEntityCount; i++) {
		T* newEntity = new T(m_textureAtlas);
		m_entities.push_back(newEntity);
		std::cout << "Entity id is: " << newEntity->GetId() << std::endl;
	}
}

template<class T>
void EntitySystem<T>::KillEntity(T* entity)
{
	RegenerateEntities();
}

template EntitySystem<Plant>;
template EntitySystem<Rabbit>;
