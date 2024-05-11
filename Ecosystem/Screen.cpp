#include "Screen.h"

Screen::Screen()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ecosystem");
	SetTargetFPS(60);

	std::list<Plant*> m_plants;
	Texture2D* grassTextureAtlas = new Texture2D(LoadTexture("Sprites/Grass.png"));
	Texture2D* rabbitTextureAtlas = new Texture2D(LoadTexture("Sprites/Rabbit.png"));

	EntitySystem<Plant>* plantSystem = new EntitySystem<Plant>(30, 50, 10, 20, grassTextureAtlas);
	EntitySystem<Animal>* rabbitSystem = new EntitySystem<Animal>(5, 8, 3, 3, rabbitTextureAtlas);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(m_backgroundColor);

		plantSystem->Update();
		rabbitSystem->Update();

		EndDrawing();
	}

	CloseWindow();
}
