#pragma once
#include "Control.h"
#include "Field.h"
#include "Monster.h"
#include "Player.h"


class CDungeon : public CField
{
public:
	CDungeon();
	~CDungeon();
public:
	void Initialize(CPlayer* _Player);
	void Release();

	void Choose_Dungeon();

	void Battle_Menu();
	bool Fight();
private:
	CMonster* m_pMonster;
	CControl m_Control;
};

