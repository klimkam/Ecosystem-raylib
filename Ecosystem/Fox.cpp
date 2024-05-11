#include "Fox.h"
#include "Screen.h"

Fox::Fox(Texture2D* texture)
{
	m_atlas = texture;
	m_entityScale = 3;
	Start();
}

void Fox::Start()
{
	Animal::Start();
	m_maxFatigue = GetRandomValue(5, 10);
}

void Fox::Update()
{
	Animal::Update();
	m_animationCurrentTimer -= GetFrameTime();
	if (m_animationCurrentTimer <= 0) {
		Animate();
	}
}

void Fox::Animate()
{
	m_animationCurrentTimer = m_animationMaxTimer;

	if (m_currentSprite * m_textureWidth >= m_atlas->width) {
		m_currentSprite = 0;
	}

	m_currentSprite++;
}

void Fox::SearchTarget()
{
	m_target = Screen::s_rabbitSystem->ClosestToThePoint(this);
	((Rabbit*)m_target)->SetHuntedBy(this);
}

void Fox::CheckCollision()
{
	float dx = (m_target->GetXPos() - m_positionX);
	float dy = (m_target->GetYPos() - m_positionY);
	float distance = std::sqrt(dx * dx + dy * dy);

	if (distance < 10) {
		if (m_currentFatigue - m_target->GetNutritionLevel() <= 0) {
			m_currentFatigue = 0;
		}
		else {
			m_currentFatigue -= m_target->GetNutritionLevel();
		}
		Screen::s_rabbitSystem->KillEntity((Rabbit*)m_target);
		Screen::s_foxSystem->ClearTargets(m_target);
	}
}

void Fox::FellAsleep()
{
	m_animalStatus = E_AnimalStatus::Sleeping;
	m_fatigueSpeed *= -3;
	m_isSleeping = true;
	ClearTarget(m_target);

	if (m_target != nullptr) {
		m_target->ClearTarget(this);
	}
}
