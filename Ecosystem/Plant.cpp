#include "Plant.h"

Plant::Plant(Texture2D* texture)
{
	m_atlas = texture;
	Start();
}
