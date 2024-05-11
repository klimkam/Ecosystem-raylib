#pragma once
#include "Animal.h"
class Fox : public Animal
{
	float m_animationMaxTimer = 0.5;
	float m_animationCurrentTimer = m_animationMaxTimer;
public:
	Fox(Texture2D* texture);

	void Start() override;
	void Update() override;

private:
	void Animate();
	void SearchTarget() override;
	void CheckCollision() override;
};

