#include "Animal.h"
#include "Screen.h"
#include <map>

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

	Vector3 position = { m_positionX, m_positionY };
}

void Animal::PrintData()
{
	Entity::PrintData();

	const char* fatigueLevel = TextFormat("Fatigue: %i", (int)m_currentFatigue);
	const char* fatigueMaxLevel = TextFormat("Max Fatigue: %i", (int)m_maxFatigue);
	const char* fatigueSpeed = TextFormat("Fatigue Speed: %i", (int)m_fatigueSpeed);
	const char* animalStatus = TextFormat(GetCurrentStatus().c_str());

	if (m_target != nullptr) {
		const char* objectId = TextFormat("Target ID: %i", m_target->GetId());
		PrintLine(objectId);
	}

	PrintLine(fatigueMaxLevel);
	PrintLine(fatigueLevel);
	PrintLine(fatigueSpeed);
	PrintLine(animalStatus);
}

void Animal::ClearTarget(Entity* target)
{
	if (m_target != target) { return; }
	m_target = nullptr;
}

void Animal::Move()
{
	if (m_target == nullptr) { SearchTarget(); return; }
	MoveToTarget();
	m_positionX += m_moveSpeedX;
	m_positionY += m_moveSpeedY;

}

void Animal::SearchTarget()
{
	m_target = Screen::s_plantSystem->ClosestToThePoint(this);
}

void Animal::MoveToTarget()
{
	if (m_target == nullptr) { return; }
	m_moveSpeedX = (m_target->GetXPos() - m_positionX) >= 0 ? m_moveSpeed : -m_moveSpeed;
	m_moveSpeedY = (m_target->GetYPos() - m_positionY) >= 0 ? m_moveSpeed : -m_moveSpeed;
	
	CheckCollision();
}

void Animal::CheckCollision()
{
	float dx = (m_target->GetXPos() - m_positionX);
	float dy = (m_target->GetYPos() - m_positionY);
	float distance = std::sqrt(dx*dx + dy*dy);

	if (distance < 10) {
		if (m_currentFatigue - m_target->GetNutritionLevel() <= 0) {
			m_currentFatigue = 0;
		}
		else {
			m_currentFatigue -= m_target->GetNutritionLevel();
		}
		Screen::s_plantSystem->KillEntity((Plant*)m_target);
		Screen::s_rabbitSystem->ClearTargets(m_target);
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

std::string const Animal::GetCurrentStatus()
{
	std::map<E_AnimalStatus, std::string> AnimalStatusToString = {
		{E_AnimalStatus::Sleeping, "Sleeping..."},
		{E_AnimalStatus::SearchingFood, "Searching Food..."},
		{E_AnimalStatus::RunningAway, "Running Away..."},
	};

	return AnimalStatusToString[m_animalStatus];
}
