#include "pch.h"
#include "Items.h"

CItems::CItems()
{
	memset(this, NULL, sizeof(*this));
}

void CItems::Initialize()
{
	switch (rand() % 2)
	{
	case ³ª¹«_¸ùµÕÀÌ:
		strcpy_s(m_szItemName, sizeof(*m_szItemName), "³ª¹« ¸ùµÕÀÌ");
		m_iBonusAtk = 10;
		break;
	case °¡Á×_°©¿Ê:
		strcpy_s(m_szItemName, sizeof(*m_szItemName), "°¡Á×_°©¿Ê");
		m_iBonusDef = 1;
		break;
	default:
		break;
	}
}

char* CItems::Get_ItemName()
{
	return m_szItemName;
}

int CItems::Get_BonusAtk()
{
	return m_iBonusAtk;
}

int CItems::Get_BonusDef()
{
	return m_iBonusDef;
}

int CItems::Get_BonusHp()
{
	return m_iBonusHp;
}

int CItems::Get_BonusMp()
{
	return m_iBonusMp;
}
