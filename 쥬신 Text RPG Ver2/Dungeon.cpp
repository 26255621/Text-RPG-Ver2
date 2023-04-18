#include "pch.h"
#include "Dungeon.h"

CDungeon::CDungeon() : m_pMonster(nullptr)
{
}

CDungeon::~CDungeon()
{
	Release();
}

void CDungeon::Initialize(CPlayer* _Player)
{
	m_pPlayer = _Player;
}

void CDungeon::Release()
{
	if (m_pMonster) {
		delete m_pMonster;
		m_pMonster = nullptr;
	}
}

void CDungeon::Choose_Dungeon()
{
	while (true) {
		int iSelect(0);
		int iX(25), iY(13);
		int iMaxY = iY;
		m_pPlayer->Show_Player();
		cout << "\n\n\t어디로 가시겠습니까? (현재위치: 던전 입구)" << endl;
		m_Control.gotoxy(iX, iMaxY);
		cout << "초보 던전";
		++iMaxY;
		m_Control.gotoxy(iX, iMaxY);
		cout << "중급 던전";
		++iMaxY;
		m_Control.gotoxy(iX, iMaxY);
		cout << "고급 던전";
		++iMaxY;
		m_Control.gotoxy(iX, iMaxY);
		cout << "뒤로";
		cout << "\n\n========================================" << endl;
		iSelect = m_Control.Draw_Arrow(iX - 2, iY, iY, iMaxY);
		
		switch (iSelect)
		{
		
		case 3:
			return;
		default:
			m_pMonster = new CMonster;
			m_pMonster->Initialize(iSelect);
			Battle_Menu();
			Release();
			break;
		}
		if (0 >= m_pPlayer->Get_Hp())
			return;
	}
}

void CDungeon::Battle_Menu()
{
	while (true) {
		m_pPlayer->Show_Player();
		m_pMonster->Show_Info();
		int iSelect(0);
		int iX(25), iY(21);
		int iMaxY = iY;
		cout << "\n\n\t행동을 선택하세요" << endl;
		m_Control.gotoxy(iX, iMaxY);
		cout << "공격";
		++iMaxY;
		m_Control.gotoxy(iX, iMaxY);
		cout << "소비 아이템 사용";
		++iMaxY;
		m_Control.gotoxy(iX, iMaxY);
		cout << "뒤로";
		cout << "\n\n============================================" << endl;
		iSelect = m_Control.Draw_Arrow(iX - 2, iY, iY, iMaxY);
		system("cls");
		switch (iSelect)
		{
		case 0:
			if (Fight())
				return;
			break;
		case 1:
			//아이템 사용
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

bool CDungeon::Fight()
{
	m_pPlayer->Creature_Damage(m_pMonster);
	m_pMonster->Creature_Damage(m_pPlayer);
	if (0 >= m_pPlayer->Get_Hp()) {
		cout << "사망!" << endl;
		system("pause");
		return true;
	}
	else if (0 >= m_pMonster->Get_Hp()) {
		m_pPlayer->Add_Gold(m_pMonster);
		m_pPlayer->Add_Exp(m_pMonster);
		m_pPlayer->Level_Up();
		m_pPlayer->Show_Player();
		cout << "승리!" << endl;
		system("pause");
		return true;
	}
	return false;
}
