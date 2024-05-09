#pragma once
#include "raylib.h"
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

public :
	Screen();
};

