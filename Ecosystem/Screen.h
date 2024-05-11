#pragma once
#include <list>
#include "raylib.h"
#include "Entity.h"
#include "Plant.h"
#include "EntitySystem.h"
#include "Animal.h"

class Screen
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	Color m_backgroundColor = Color{ 20, 160, 133, 255 };
	
	int m_ballX = 100;
	int m_ballY = 100;

	int m_ballSpeedX = 5;
	int m_ballSpeedY = 5;

	int m_ballRadius = 15;

	static Texture2D* s_grassTextureAtlas;
	static Texture2D* s_rabbitTextureAtlas;
	static Texture2D* s_foxTextureAtlas;

public :
	Screen();

	static EntitySystem<Plant>* s_plantSystem;
	static EntitySystem<Rabbit>* s_rabbitSystem;
	static EntitySystem<Fox>* s_foxSystem;
};

