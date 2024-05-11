#include "Screen.h"

EntitySystem<Plant>* Screen::s_plantSystem = new EntitySystem<Plant>();
EntitySystem<Rabbit>* Screen::s_rabbitSystem = new EntitySystem<Rabbit>();
EntitySystem<Fox>* Screen::s_foxSystem = new EntitySystem<Fox>();

Screen::Screen()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ecosystem");
	SetTargetFPS(60);

	Texture2D* s_grassTextureAtlas = new Texture2D(LoadTexture("Sprites/Grass.png"));
	Texture2D* s_rabbitTextureAtlas = new Texture2D(LoadTexture("Sprites/Rabbit.png"));
	Texture2D* s_foxTextureAtlas = new Texture2D(LoadTexture("Sprites/Fox.png"));

	s_plantSystem = new EntitySystem<Plant>(30, 50, 10, 20, s_grassTextureAtlas);
	s_rabbitSystem = new EntitySystem<Rabbit>(5, 8, 3, 3, s_rabbitTextureAtlas);
	s_foxSystem = new EntitySystem<Fox>(2, 3, 0, 0, s_foxTextureAtlas);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(m_backgroundColor);

		s_plantSystem->Update();
		s_rabbitSystem->Update();
		s_foxSystem->Update();

		EndDrawing();
	}

	CloseWindow();
}
