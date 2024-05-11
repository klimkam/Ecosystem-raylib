#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(Texture2D* texture);

	void Start() override;
};

