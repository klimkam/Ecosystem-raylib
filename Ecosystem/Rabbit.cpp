#include "Rabbit.h"

Rabbit::Rabbit(Texture2D* texture)
{
	m_atlas = texture;
	m_entityScale = 3;
	Start();
}

void Rabbit::Start()
{
	Animal::Start();
}
