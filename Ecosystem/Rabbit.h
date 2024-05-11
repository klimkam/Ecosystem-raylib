#pragma once
#include "Animal.h"
class Rabbit :public Animal
{
public:
	Rabbit(Texture2D* texture);

	void Start() override;
};

