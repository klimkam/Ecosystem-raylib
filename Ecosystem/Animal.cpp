#include "Animal.h"

Animal::Animal()
{
}

Animal::Animal(Texture2D* texture)
{
	m_atlas = texture;
	m_entityScale = 3;
	Start();
}

void Animal::Update()
{
	Entity::Update();
	if (!m_isSleeping) {
		Move();
	}

	if (m_currentFatigue >= m_maxFatigue && !m_isSleeping) {
		FellAsleep();
	}

	if (m_currentFatigue <= 0 && m_isSleeping) {
		WakeUp();
	}

	m_currentFatigue += (GetFrameTime() * m_fatigueSpeed);
}

void Animal::Start()
{
	Entity::Start();

	m_moveSpeedX = GetRandomValue(-5, 5);
	m_moveSpeedY = GetRandomValue(-5, 5);
}

void Animal::PrintData()
{
	Entity::PrintData();

	const char* fatigueLevel = TextFormat("Fatigue: %i", (int)m_currentFatigue);
	const char* fatigueMaxLevel = TextFormat("Max Fatigue: %i", (int)m_maxFatigue);
	const char* fatigueSpeed = TextFormat("Fatigue Speed: %i", (int)m_fatigueSpeed);


	PrintLine(fatigueMaxLevel);
	PrintLine(fatigueLevel);
	PrintLine(fatigueSpeed);
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

void Animal::FellAsleep()
{
	m_animalStatus = E_AnimalStatus::Sleeping;
	m_fatigueSpeed *= -3;
	m_isSleeping = true;
}

void Animal::WakeUp()
{
	m_animalStatus = E_AnimalStatus::SearchingFood;
	m_fatigueSpeed /= -3;
	m_isSleeping = false;
}
