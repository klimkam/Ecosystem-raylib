#include "Entity.h"

Entity::Entity()
{
	SetUpTexture();
}

void Entity::SetUpTexture()
{
	m_atlas = LoadTexture("Sprites/Grass.png");
}

void Entity::DrawEntity()
{
	Rectangle source = Rectangle{ 
		(float)(0 + m_currentSprite * m_textureWidth),
		(float)(0 + m_currentSprite * m_textureWidth),
		(float)((m_currentSprite + 1) * m_textureWidth),
		(float)((m_currentSprite + 1) * m_textureWidth) };
	Rectangle dest = Rectangle{ 
		(m_positionX),
		(m_positionY),
		source.width * m_entityScale,
		source.height * m_entityScale };
	DrawTexturePro(m_atlas, source, dest, Vector2{dest.width/2, dest.height / 2 }, 0, WHITE);
}
