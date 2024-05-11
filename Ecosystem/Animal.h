#pragma once
#include "Entity.h"
#include "Enums.h"

class Animal : public Entity
{
	float m_moveSpeed = 1;
	float m_moveSpeedX = m_moveSpeed;
	float m_moveSpeedY = m_moveSpeed;

	float m_radius = 16;

	E_AnimalStatus m_animalStatus = E_AnimalStatus::Count;

	float m_currentFatigue = 0;
	float m_maxFatigue = 10;
	int m_fatigueSpeed = 1;
	bool m_isSleeping = false;

public:
	Animal();
	Animal(Texture2D* texture);

	void Update() override;
	void Start() override;

	void PrintData() override;

private:
	void Move();
	void FellAsleep();
	void WakeUp();
};

