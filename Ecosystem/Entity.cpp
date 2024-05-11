#include "Entity.h"

Entity::Entity()
{
	Start();
}

Entity::Entity(Texture2D* atlas)
{
	m_atlas = atlas;
	Start();
}

void Entity::Start()
{
}

void Entity::Update()
{
	DrawEntity();
}

void Entity::DrawEntity()
{
	Rectangle source = Rectangle{ 
		(float)(m_currentSprite * m_textureWidth),
		(float)(0),
		(float)(m_textureWidth),
		(float)(m_textureWidth) };
	Rectangle dest = Rectangle{ 
		(m_positionX),
		(m_positionY),
		source.width * m_entityScale,
		source.height * m_entityScale };
	DrawTexturePro((*m_atlas), source, dest, Vector2{dest.width/2, dest.height / 2 }, 0, WHITE);
}
