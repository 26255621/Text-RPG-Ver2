#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
{
	memset(this, NULL, sizeof(*this));
}

CMonster::~CMonster()
{
}

void CMonster::Initialize(int _Diff)
{
	switch (_Diff)
	{
	case EASY:
		strcpy_s(m_szName, "슬라임");
		break;
	case NORMAL:
		strcpy_s(m_szName, "고블린");
		break;
	case HARD:
		strcpy_s(m_szName, "오거");
		break;
	default:
		break;
	}
	m_iAtk = 3;
	m_iDef = 0;
	m_iHp = m_iMaxHp = 30 + 30 * _Diff;
	m_iMp = m_iMaxMp = 10 + 10 * _Diff;
	m_iExtraAtk = m_iAtk + m_iAtk * _Diff;
	m_iExp = 30 + 30 * _Diff;
	m_iGold = 30 + 30 * _Diff;
}

void CMonster::Release()
{

}
