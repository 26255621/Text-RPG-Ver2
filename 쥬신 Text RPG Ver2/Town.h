#pragma once
#include "Field.h"
#include "Player.h"
#include "Items.h"
#include "Dungeon.h"

class CTown : public CField
{
public:
	CTown();
	~CTown();
public:
	void Initialize(CPlayer* _Player);
	void Release();

	int Plaza();
	void Hospital();
	void Shop();
private:
	CDungeon *m_Dungeon;
};

