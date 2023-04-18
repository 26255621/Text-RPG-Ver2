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
}

void CPlayer::Update()
{
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
	cout << "\n\n\t�̸��� �Է��ϼ���(�̸� �Է��� ����)\n" << endl;
	cout << "\t\t";
	cin >> szName;
	m_Control.CursorView();
	int iX(25), iY(5);
	int iMaxY = iY;
	system("cls");
	cout << "\n\n\t� ������ ���ðڽ��ϱ�?" << endl;
	m_Control.gotoxy(iX, iMaxY);
	cout << "����";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "������";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "����" << endl;
	cout << "\n\n========================================" << endl;
	iSelect = m_Control.Draw_Arrow(iX - 2, iY, iY, iMaxY);
	switch (iSelect)
	{
	case 1:
		Initialize(szName, (char*)"����");
		break;
	case 2:
		Initialize(szName, (char*)"������");
		break;
	case 3:
		Initialize(szName, (char*)"����");
		break;
	default:
		break;
	}
}
