#pragma once
#include "Entity.h"
class Animal : public Entity
{
	float m_moveSpeed = 1;
	float m_moveSpeedX = m_moveSpeed;
	float m_moveSpeedY = m_moveSpeed;

	float m_radius = 16;

public:
	Animal(Texture2D* texture);

	void Update() override;
	void Start() override;

private:
	void Move();
};

