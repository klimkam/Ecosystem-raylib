#pragma once
#include "Animal.h"
#include <list>
class Rabbit :public Animal
{
	std::list<Entity*> m_huntedBy;
	void RunAway() override;
	void WakeUp() override;

public:
	Rabbit(Texture2D* texture);
	void Start() override;

	void SetHuntedBy(Entity* entity);
	void ClearHuntedBy(Entity* entity);
};

