#include "Screen.h"

Screen::Screen()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ecosystem");
	SetTargetFPS(60);

	Texture2D* grassTextureAtlas = new Texture2D(LoadTexture("Sprites/Grass.png"));
	Texture2D* rabbitTextureAtlas = new Texture2D(LoadTexture("Sprites/Rabbit.png"));
	Texture2D* foxTextureAtlas = new Texture2D(LoadTexture("Sprites/Fox.png"));

	EntitySystem<Plant>* plantSystem = new EntitySystem<Plant>(30, 50, 10, 20, grassTextureAtlas);
	EntitySystem<Rabbit>* rabbitSystem = new EntitySystem<Rabbit>(5, 8, 3, 3, rabbitTextureAtlas);
	EntitySystem<Fox>* foxSystem = new EntitySystem<Fox>(2, 3, 0, 0, foxTextureAtlas);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(m_backgroundColor);

		plantSystem->Update();
		rabbitSystem->Update();
		foxSystem->Update();

		EndDrawing();
	}

	CloseWindow();
}
