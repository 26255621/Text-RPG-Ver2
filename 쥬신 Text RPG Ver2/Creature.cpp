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
	cout << "�̸�: " << m_szName << endl;
	cout << "���ݷ�: " << m_iAtk << endl;
	cout << "ü��: " << setw(4) << m_iHp << '/' << setw(4) << m_iMaxHp << endl;
	cout << "����: " << setw(4) << m_iMp << '/' << setw(4) << m_iMaxMp << endl;
	cout << "����ġ: " << setw(4) << m_iExp << endl;
	cout << "������: " << setw(5) << m_iGold << endl;
}
