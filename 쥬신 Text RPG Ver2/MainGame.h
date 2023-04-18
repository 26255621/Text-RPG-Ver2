#pragma once
#include "Player.h"
#include "Control.h"
#include "Town.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();
public:
	void Initialize();
	void Update();
	void Release();

	int MainMenu();
	void Load_File();
	void Save_File();
private:
	CPlayer* m_pPlayer;
	CControl m_Control;
	CTown* m_Town;
};

