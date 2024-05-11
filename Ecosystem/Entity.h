#pragma once
#include "raylib.h"
#include <iostream>

class Entity
{
	int static unsigned NextAvailableId;
protected:
	int m_id;
	float m_positionX = GetScreenWidth()/2;
	float m_positionY = GetScreenHeight()/2;

	float m_entityScale = 5;

	const Texture2D* m_atlas;
	int m_currentSprite = 1;
	int const m_textureWidth = 16;


	int const m_fontSize = 10;
	int m_currentLine = 0;

	void virtual PrintData();
	void PrintLine(const char* textLine);

public:
	Entity();
	Entity(const Texture2D* atlas);
	void virtual Start();
	void virtual Update();
	int const GetId();

private:
	void const DrawEntity();
	int SetId();
};

