#pragma once
#include "Control.h"
#include "Player.h"

class CPlaza
{
public:
	CPlaza();
	~CPlaza();
public:
	void Initialize(CPlayer* _Player);
	void Release();


protected:
	CPlayer* m_pPlayer;
	CControl m_Control;

};

