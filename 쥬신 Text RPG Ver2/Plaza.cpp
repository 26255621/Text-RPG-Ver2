#include "pch.h"
#include "Plaza.h"

CPlaza::CPlaza() :m_pPlayer(nullptr)
{
}

CPlaza::~CPlaza()
{
	Release();
}

void CPlaza::Initialize(CPlayer* _Player)
{
	m_pPlayer = _Player;
}

void CPlaza::Release()
{
	if (m_pPlayer) {
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}
}
