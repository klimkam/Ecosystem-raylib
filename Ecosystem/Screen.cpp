#include "Screen.h"

Screen::Screen()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ecosystem");
	SetTargetFPS(60);

	std::list<Plant*> m_plants;
	Texture2D* grassTextureAtlas = new Texture2D(LoadTexture("Sprites/Grass.png"));

	EntitySystem<Plant>* plantSystem;
	plantSystem = new EntitySystem<Plant>(30, 50, 10, 20, grassTextureAtlas);

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

		plantSystem->Update();

		DrawCircle(m_ballX, m_ballY, m_ballRadius, WHITE);
		EndDrawing();
	}

	CloseWindow();
}
