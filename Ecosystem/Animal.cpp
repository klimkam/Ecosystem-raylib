#include "Animal.h"

Animal::Animal(Texture2D* texture)
{
	m_atlas = texture;
	m_entityScale = 3;
	Start();
}

void Animal::Update()
{
	Entity::Update();
	Move();
}

void Animal::Start()
{
	Entity::Start();

	m_moveSpeedX = GetRandomValue(-5, 5);
	m_moveSpeedY = GetRandomValue(-5, 5);
}

void Animal::Move()
{
	m_positionX += m_moveSpeedX;
	m_positionY += m_moveSpeedY;

	if (m_positionX + m_radius >= GetScreenWidth() || m_positionX - m_radius <= 0) {
		m_moveSpeedX *= -1;
	}
	if (m_positionY + m_radius >= GetScreenHeight() || m_positionY - m_radius <= 0) {
		m_moveSpeedY *= -1;
	}
}
