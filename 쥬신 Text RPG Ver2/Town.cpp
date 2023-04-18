#include "pch.h"
#include "Town.h"

CTown::CTown() : m_Dungeon(nullptr)
{
}

CTown::~CTown()
{
	Release();
}

void CTown::Initialize(CPlayer* _Player)
{
	m_pPlayer = _Player;
	m_Dungeon = new CDungeon;
	m_Dungeon->Initialize(m_pPlayer);
}

void CTown::Release()
{
	if (m_Dungeon) {
		delete m_Dungeon;
		m_Dungeon = nullptr;
	}
}

int CTown::Plaza()
{
	int iSelect(0);
	int iX(25), iY(13);
	int iMaxY = iY;
	m_pPlayer->Show_Player();
	cout << "\n\n\t���� ���ðڽ��ϱ�? (������ġ: ���� ����)" << endl;
	m_Control.gotoxy(iX, iMaxY);
	cout << "����";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "���� (��� ġ�� 100 G)";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "����";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "��� ����";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "����";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "����";
	cout << "\n\n========================================" << endl;
	iSelect = m_Control.Draw_Arrow(iX - 2, iY, iY, iMaxY);
	switch (iSelect)
	{
	case 0:
		m_Dungeon->Choose_Dungeon();
		break;
	case 1:
		// ����
		Hospital();
		break;
	case 2:
		// ����
		Shop();
		break;
	case 3:
		// ��� ����
		break;
	case 4:
		// ����
		return iSelect;
	case 5:
		// ����
		return iSelect;
	default:
		break;
	}
	return iSelect;
}

void CTown::Hospital()
{
	system("cls");
	m_pPlayer->Show_Player();
	if (100 <= m_pPlayer->Get_Gold()) {
		m_pPlayer->Set_Hp(m_pPlayer->Get_ExtraHp());
		m_pPlayer->Set_MaxMp(m_pPlayer->Get_ExtraMp());
		m_pPlayer->Lost_Gold(100);
		cout << "\nġ�� �Ϸ�!" << endl;
	}
	else
		cout << "\n������ ����!" << endl;
	system("pause");

}

void CTown::Shop()
{
}
