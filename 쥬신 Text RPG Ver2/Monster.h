#pragma once
#include "Creature.h"

enum Diff {
	EASY,
	NORMAL,
	HARD
};

class CMonster : public CCreature
{
public:
	CMonster();
	~CMonster();
public:
	void Initialize(int _Diff);
	void Release();

private:
};

