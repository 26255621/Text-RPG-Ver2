#include "pch.h"
#include "Town.h"

void CTown::Initialize(CPlayer* _Player)
{
	m_pPlayer = _Player;
}

int CTown::Plaza()
{
	int iSelect(0);
	int iX(25), iY(13);
	int iMaxY = iY;
	m_pPlayer->Show_Player();
	cout << "\n\n\t어디로 가시겠습니까? (현재위치: 마을 광장)" << endl;
	m_Control.gotoxy(iX, iMaxY);
	cout << "던전";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "병원 (모두 치료 100 G)";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "상점";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "장비 변경";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "저장";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "종료";
	cout << "\n\n========================================" << endl;
	iSelect = m_Control.Draw_Arrow(iX - 2, iY, iY, iMaxY);
	switch (iSelect)
	{
	case 0:
		// Todo: 던전
		break;
	case 1:
		// inn
		Hospital();
		break;
	case 2:
		// shop
		Shop();
		break;
	case 3:
		// 장비 변경
		break;
	case 4:
		// 저장
		return iSelect;
	case 5:
		// 종료
		return iSelect;
	default:
		break;
	}
}

void CTown::Hospital()
{
	system("cls");
	m_pPlayer->Show_Player();
	if (100 <= m_pPlayer->Get_Gold()) {
		m_pPlayer->Set_Hp(m_pPlayer->Get_ExtraHp());
		m_pPlayer->Set_MaxMp(m_pPlayer->Get_ExtraMp());
		m_pPlayer->Lost_Gold(100);
		cout << "\n치료 완료!" << endl;
	}
	else
		cout << "\n소지금 부족!" << endl;
	system("pause");

}

void CTown::Shop()
{
}
