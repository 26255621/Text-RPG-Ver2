#pragma once
#include "Creature.h"

class CMonster : public CCreature
{
public:
	CMonster();
	~CMonster();
public:
	void Initialize();
	void Release();

private:
};

