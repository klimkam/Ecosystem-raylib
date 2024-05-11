#pragma once
#include "Entity.h"
class Animal : public Entity
{
public:
	Animal(Texture2D* texture);

	void Update() override;
};

