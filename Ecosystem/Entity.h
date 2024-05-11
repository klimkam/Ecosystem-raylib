#pragma once
#include "raylib.h"

class Entity
{
protected:
	float m_positionX = GetScreenWidth()/2;
	float m_positionY = GetScreenHeight()/2;

	float m_entityScale = 5;

	int m_currentSprite = 1;
	int m_textureWidth = 16;

	Texture2D* m_atlas;

public:
	Entity();
	Entity(Texture2D* atlas);
	void virtual Start();
	void virtual Update();

private:
	void DrawEntity();
};

