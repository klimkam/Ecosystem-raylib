#include "Screen.h"
#include "Entity.h"
#include <list>
#include "Plant.h"

Screen::Screen()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ecosystem");
	SetTargetFPS(60);

	std::list<Plant*> m_plants;
	Texture2D* grassTextureAtlas = new Texture2D(LoadTexture("Sprites/Grass.png"));
	int plantsAmount = GetRandomValue(30, 50);
	for (int i = 0; i < plantsAmount; i++) {
		m_plants.push_back(new Plant(grassTextureAtlas));
	}

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(m_backgroundColor);

		m_ballX += m_ballSpeedX;
		m_ballY += m_ballSpeedY;

		if (m_ballX + m_ballRadius >= GetScreenWidth() || m_ballX - m_ballRadius <=0) {
			m_ballSpeedX *= -1;
		}
		if (m_ballY + m_ballRadius >= GetScreenHeight() || m_ballY - m_ballRadius <=0) {
			m_ballSpeedY *= -1;
		}

		for(Plant* plant : m_plants)
		{
			plant->DrawEntity();
		}

		DrawCircle(m_ballX, m_ballY, m_ballRadius, WHITE);
		EndDrawing();
	}

	CloseWindow();
}
