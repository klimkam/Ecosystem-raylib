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
