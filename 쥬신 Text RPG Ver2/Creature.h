#pragma once
#include "Stat.h"

class CCreature
{
public:
	CCreature();
	~CCreature();
public:
	void Creature_Damage(CCreature* _Creature);
	void Add_Gold(CCreature* _Creature);
	void Lost_Gold(int _Price);
	void Add_Exp(CCreature* _Creature);

	void Show_Info();

public:
	int Get_Hp() { return m_iHp; }
	int Get_Gold() { return m_iGold; }


	void Set_ExtraAtk(int _ExtraAtk) { m_iExtraAtk = _ExtraAtk; }
	void Set_Atk(int _Atk) { m_iAtk = _Atk; }
	void Set_ExtraDef(int _ExtraDef) { m_iExtraDef = _ExtraDef; }
	void Set_Def(int _Def) { m_iDef = _Def; }
	void Set_ExtraHp(int _ExtraHp) { m_iExtraHp = _ExtraHp; }
	void Set_MaxHp(int _MaxHp) { m_iMaxHp = _MaxHp; }
	void Set_Hp(int _Hp) { m_iHp = _Hp; }
	void Set_ExtraMp(int _ExtraMp) { m_iExtraMp = _ExtraMp; }
	void Set_MaxMp(int _MaxMp) { m_iMaxMp = _MaxMp; }
	void Set_Mp(int _Mp) { m_iMp = _Mp; }

	char* Get_Name() { return m_szName; }
	int Get_ExtraAtk() { return m_iExtraAtk; }
	int Get_Atk() { return m_iAtk; }
	int Get_ExtraDef() { return m_iExtraDef; }
	int Get_Def() { return m_iDef; }
	int Get_ExtraHp() { return m_iExtraHp; }
	int Get_MaxHp() { return m_iMaxHp; }
	int Get_ExtraMp() { return m_iExtraMp; }
	int Get_MaxMp() { return m_iMaxMp; }
	int Get_Mp() { return m_iMp; }
protected:
	char m_szName[16];
	int m_iExtraAtk, m_iAtk;
	int m_iExtraDef, m_iDef;
	int m_iExtraHp, m_iMaxHp, m_iHp;
	int m_iExtraMp, m_iMaxMp, m_iMp;
	int m_iExp;
	int m_iGold;
};