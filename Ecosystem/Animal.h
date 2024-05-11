#pragma once
#include "Plant.h"
#include "Enums.h"

class Animal : public Entity
{
protected:
	float m_moveSpeed = 1;
	float m_moveSpeedX = m_moveSpeed;
	float m_moveSpeedY = m_moveSpeed;

	E_AnimalStatus m_animalStatus = E_AnimalStatus::SearchingFood;

	float m_currentFatigue = 0;
	float m_maxFatigue = 10;
	int m_fatigueSpeed = 1;
	bool m_isSleeping = false;

	Entity* m_target = nullptr;
	
public:
	Animal();
	Animal(Texture2D* texture);

	void Update() override;
	void Start() override;

	void PrintData() override;

private:
	void Move();
	void Wonder();
	void MoveToTarget(Entity target);
	void FellAsleep();
	void WakeUp();
	std::string const GetCurrentStatus();
};

