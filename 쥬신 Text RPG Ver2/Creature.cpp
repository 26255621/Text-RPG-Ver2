#include "pch.h"
#include "Creature.h"

CCreature::CCreature()
{
	memset(this, NULL, sizeof(*this));
}

CCreature::~CCreature()
{
}

char* CCreature::Get_Name()
{
	return m_szName;
}

int CCreature::Get_ExtraAtk()
{
	return m_iExtraAtk;
}

int CCreature::Get_Atk()
{
	return m_iAtk;
}

int CCreature::Get_ExtraDef()
{
	return m_iExtraDef;
}

int CCreature::Get_Def()
{
	return m_iDef;
}

int CCreature::Get_ExtraHp()
{
	return m_iExtraHp;
}

int CCreature::Get_MaxHp()
{
	return m_iMaxHp;
}

int CCreature::Get_Hp()
{
	return m_iHp;
}

int CCreature::Get_ExtraMp()
{
	return m_iExtraMp;
}

int CCreature::Get_MaxMp()
{
	return m_iMaxMp;
}

int CCreature::Get_Mp()
{
	return m_iMp;
}
