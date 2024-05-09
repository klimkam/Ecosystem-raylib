#pragma once
#include "raylib.h"

class Entity
{
	float m_positionX = GetScreenWidth()/2;
	float m_positionY = GetScreenHeight()/2;

	float m_entityScale = 5;

	int m_currentSprite = 0;
	int m_textureWidth = 16;

	Texture2D m_atlas;

public:
	Entity();
	void DrawEntity();

private:
	void virtual SetUpTexture();
};

