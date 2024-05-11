#include "Rabbit.h"

void Rabbit::RunAway()
{
	if (m_huntedBy.size() == 0) { return; }
	if (m_huntedBy.front() == nullptr) { return; }
	m_moveOrientationX = (m_huntedBy.front()->GetXPos() - m_positionX) >= 0 ? -m_moveSpeed : m_moveSpeed;
	m_moveOrientationY = (m_huntedBy.front()->GetYPos() - m_positionY) >= 0 ? -m_moveSpeed : m_moveSpeed;

}

Rabbit::Rabbit(Texture2D* texture)
{
	m_atlas = texture;
	m_entityScale = 3;
	Start();
}

void Rabbit::Start()
{
	Animal::Start();
	m_maxFatigue = GetRandomValue(5, 10);
}

void Rabbit::SetHuntedBy(Entity* entity)
{
	m_huntedBy.push_back(entity);
	m_animalStatus = E_AnimalStatus::RunningAway;
}

void Rabbit::ClearHuntedBy(Entity* entity)
{
	m_huntedBy.remove(entity);

	if (m_huntedBy.size() == 0) {
		m_animalStatus = E_AnimalStatus::SearchingFood;
	}
}
