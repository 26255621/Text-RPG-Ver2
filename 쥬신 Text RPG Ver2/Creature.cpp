#include "pch.h"
#include "Creature.h"

CCreature::CCreature()
{
	memset(this, NULL, sizeof(*this));
}

CCreature::~CCreature()
{
}

void CCreature::Creature_Damage(CCreature* _Creature)
{
	m_iHp -= _Creature->m_iExtraAtk;
}

void CCreature::Add_Gold(CCreature* _Creature)
{
	m_iGold += _Creature->m_iGold;
}

void CCreature::Lost_Gold(int _Price)
{
	m_iGold -= _Price;
}

void CCreature::Add_Exp(CCreature* _Creature)
{
	m_iExp += _Creature->m_iExp;
}

void CCreature::Show_Info()
{
	cout << "============================================" << endl;
	cout << "이름: " << m_szName << endl;
	cout << "공격력: " << m_iAtk << endl;
	cout << "체력: " << setw(4) << m_iHp << '/' << setw(4) << m_iMaxHp << endl;
	cout << "마나: " << setw(4) << m_iMp << '/' << setw(4) << m_iMaxMp << endl;
	cout << "경험치: " << setw(4) << m_iExp << endl;
	cout << "소지금: " << setw(5) << m_iGold << endl;
}
