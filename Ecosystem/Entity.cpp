#include "Entity.h"

Entity::Entity()
{
	SetId();
}

Entity::Entity(Texture2D* atlas)
{
	m_atlas = atlas;
	SetId();
}

void Entity::Start()
{
	m_currentSprite = GetRandomValue(0, (*m_atlas).width / m_textureWidth);

	m_positionX = GetRandomValue(m_textureWidth, GetScreenWidth() - m_textureWidth);
	m_positionY = GetRandomValue(m_textureWidth, GetScreenHeight() - m_textureWidth);
}

void Entity::Update()
{
	DrawEntity();
}

int Entity::GetId()
{
	return m_id;
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

void Entity::SetId()
{
	m_id = NextAvailableId++;
}
