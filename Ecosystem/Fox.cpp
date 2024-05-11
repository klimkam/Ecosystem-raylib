#include "Fox.h"

Fox::Fox(Texture2D* texture)
{
	m_atlas = texture;
	m_entityScale = 3;
	Start();
}

void Fox::Start()
{
	Animal::Start();
	m_maxFatigue = GetRandomValue(10, 20);
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
