#include "pch.h"
#include "Player.h"



CPlayer::CPlayer()
{
	memset(this, NULL, sizeof(*this));
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(char* _szName, char* _szJob)
{
	m_pWeapon = new CItems;
	m_pArmor = new CItems;
	strcpy_s(m_szName, sizeof(m_szName), _szName);
	strcpy_s(m_szJob, sizeof(m_szJob), _szJob);

	m_iExtraAtk = m_iAtk = 10;
	m_iExtraHp = m_iMaxHp = m_iHp = 100;
	m_iExtraMp = m_iMaxMp = m_iMp = 20;
	m_iMaxExp = 150;
	m_iLevel = 1;
	m_iGold = 100;
}

void CPlayer::Update()
{
	if(!m_pWeapon)
		m_iExtraAtk = m_iAtk + m_pWeapon->Get_BonusAtk();
	if (!m_pArmor) {
		m_iExtraDef = m_iDef + m_pArmor->Get_BonusDef();
		m_iExtraHp = m_iMaxHp + m_pArmor->Get_BonusHp();
		m_iExtraMp = m_iMaxMp + m_pArmor->Get_BonusMp();
	}
}

void CPlayer::Release()
{
	if (m_pWeapon) {
		delete m_pWeapon;
		m_pWeapon = nullptr;
	}
	if (m_pArmor) {
		delete m_pArmor;
		m_pArmor = nullptr;
	}
}

void CPlayer::Make_Player()
{
	int iSelect(0);
	char szName[16];
	system("cls");
	m_Control.CursorView(true);
	cout << "\n\n\t이름을 입력하세요(이름 입력후 엔터)\n" << endl;
	cout << "\t\t";
	cin >> szName;
	m_Control.CursorView();
	int iX(25), iY(5);
	int iMaxY = iY;
	system("cls");
	cout << "\n\n\t어떤 직업을 고르시겠습니까?" << endl;
	m_Control.gotoxy(iX, iMaxY);
	cout << "전사";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "마법사";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "돚거" << endl;
	cout << "\n\n========================================" << endl;
	iSelect = m_Control.Draw_Arrow(iX - 2, iY, iY, iMaxY);
	switch (iSelect)
	{
	case 0:
		Initialize(szName, (char*)"전사");
		break;
	case 1:
		Initialize(szName, (char*)"마법사");
		break;
	case 2:
		Initialize(szName, (char*)"돚거");
		break;
	default:
		break;
	}
}

void CPlayer::Show_Player()
{
	system("cls");
	cout << "============================================" << endl;
	cout << "이름: " << m_szName << "\t직업: " << m_szJob << endl;
	cout << "공격력: " << setw(3) << m_iExtraAtk << '\t' << "방어력: " << setw(3) << m_iExtraDef << endl;
	cout << "체력: " << setw(4) << m_iHp << '/' << setw(4) << m_iExtraHp << endl;
	cout << "마나: " << setw(4) << m_iMp << '/' << setw(4) << m_iExtraMp << endl;
	cout << "경험치: " << setw(4) << m_iExp << '/' << setw(4) << m_iMaxExp << '\t' << "레벨: " << setw(2) << m_iLevel << endl;
	cout << "소지금: " << setw(5) << m_iGold << endl;
}

void CPlayer::Level_Up()
{
	if (m_iExp > m_iMaxExp) {
		m_iHp = m_iMaxHp += 10;
		m_iMp = m_iMaxMp += 10;

		m_iMaxExp += 50;
		m_iExp = 0;
		++m_iLevel;
	}
}

