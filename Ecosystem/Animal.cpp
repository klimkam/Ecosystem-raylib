#include "Animal.h"

Animal::Animal(Texture2D* texture)
{
	m_atlas = texture;
	m_entityScale = 3;
	Start();
}
