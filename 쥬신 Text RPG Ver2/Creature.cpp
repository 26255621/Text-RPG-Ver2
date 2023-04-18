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
