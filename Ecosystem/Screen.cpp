#include "Screen.h"
#include "Entity.h"

Screen::Screen()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ecosystem");
	SetTargetFPS(60);

	Entity* entity = new Entity();

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

		entity->DrawEntity();

		DrawCircle(m_ballX, m_ballY, m_ballRadius, WHITE);
		EndDrawing();
	}

	CloseWindow();
}
