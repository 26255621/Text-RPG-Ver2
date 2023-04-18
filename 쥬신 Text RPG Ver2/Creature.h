#pragma once
#include "Stat.h"

class CCreature
{
public:
	CCreature();
	~CCreature();

public:
	char* Get_Name();
	int Get_ExtraAtk();
	int Get_Atk();
	int Get_ExtraDef();
	int Get_Def();
	int Get_ExtraHp();
	int Get_MaxHp();
	int Get_Hp();
	int Get_ExtraMp();
	int Get_MaxMp();
	int Get_Mp();
protected:
	char m_szName[16];
	int m_iExtraAtk, m_iAtk;
	int m_iExtraDef, m_iDef;
	int m_iExtraHp, m_iMaxHp, m_iHp;
	int m_iExtraMp, m_iMaxMp, m_iMp;
};