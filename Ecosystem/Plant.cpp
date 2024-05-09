#include "Plant.h"

Plant::Plant(Texture2D* texture)
{
	m_atlas = texture;
	Start();
}

void Plant::Start()
{
	m_currentSprite = GetRandomValue(0, (*m_atlas).width/ m_textureWidth);

	m_positionX = GetRandomValue(0 + m_textureWidth, GetScreenWidth() - m_textureWidth);
	m_positionY = GetRandomValue(0 + m_textureWidth, GetScreenHeight() - m_textureWidth);
}
