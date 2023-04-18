#pragma once
#include "Control.h"
#include "Creature.h"
#include "Items.h"

class CPlayer : public CCreature
{
public:
	CPlayer();
	~CPlayer();
public:
	void Initialize(char* _szName, char* _szJob);
	void Update();
	void Release();

	void Make_Player();
	void Show_Player();

	void Level_Up();
	void ChangeEquiment();


private:
	char m_szJob[8];
	int m_iMaxExp;
	int m_iLevel;
	CItems* m_pWeapon;
	CItems* m_pArmor;

	CControl m_Control;
};

