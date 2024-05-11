#include "EntitySystem.h"

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
	}
}

template<class T>
void EntitySystem<T>::RegenerateEntities()
{
	if (m_entities.size() > m_minimalEntityCount) { return; }

	for (int i = 0; i < m_regenerateEntityCount; i++) {
		T* newEntity = new T(m_textureAtlas);
		m_entities.push_back(newEntity);
	}
}

template<class T>
void EntitySystem<T>::KillEntity(T* entity)
{
	T* tempEntity = entity;
	m_entities.remove(entity);
	delete entity;
	RegenerateEntities();
}

template<class T>
T* EntitySystem<T>::GetRandomEntity()
{
	if (m_entities.size() <= 0) { return nullptr; }
	auto m_entitiesIterator = m_entities.begin();
	return *m_entitiesIterator;
}

template<class T>
T* EntitySystem<T>::ClosestToThePoint(float posX, float posY)
{
	auto m_entitiesIterator = m_entities.begin();
	T* tempEntity = nullptr;
	float currentDistance = 1000;

	while (m_entitiesIterator != m_entities.end()) {
		m_entitiesIterator++;

		float diffX = posX - tempEntity->GetXPos();
		float diffY = posY - tempEntity->GetYPos();
		float tempCurrentDistance = std::sqrt(diffX * diffX + diffY * diffY);
		if (currentDistance > tempCurrentDistance) {
			tempEntity = *m_entitiesIterator;
		}
	}

	return *m_entitiesIterator;
}

template EntitySystem<Plant>;
template EntitySystem<Rabbit>;
template EntitySystem<Fox>;
