#include "pch.h"
#include "MainGame.h"



CMainGame::CMainGame() : m_pPlayer(nullptr)
{

}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_Control.CursorView();
	m_pPlayer = new CPlayer;
}

void CMainGame::Update()
{
	if (2 == MainMenu())
		return;
	while (true) {
		// 캐릭터 사망시 처음부터 시작하자
		if (0 >= m_pPlayer->Get_Hp()) {
			Release();
			Initialize();
			m_pPlayer->Make_Player();
		}

	}

}

void CMainGame::Release()
{
	if (m_pPlayer) {
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}
}

int CMainGame::MainMenu()
{
	cout << "\n\n\n";
	cout << "\t########.########.##.....##.########....########..########...######.." << endl;
	cout << "\t...##....##........##...##.....##.......##.....##.##.....##.##....##." << endl;
	cout << "\t...##....##.........##.##......##.......##.....##.##.....##.##......." << endl;
	cout << "\t...##....######......###.......##.......########..########..##...####" << endl;
	cout << "\t...##....##.........##.##......##.......##...##...##........##....##." << endl;
	cout << "\t...##....##........##...##.....##.......##....##..##........##....##." << endl;
	cout << "\t...##....########.##.....##....##.......##.....##.##.........######.." << endl;
	PlaySound(TEXT("Data/Titanium.wav"), NULL, SND_FILENAME | SND_ASYNC);

	int iSelect(0);
	int iX(35), iY(13);
	int iMaxY = iY;
	m_Control.gotoxy(iX, iY);
	cout << "게임 시작";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "불러 오기";
	++iMaxY;
	m_Control.gotoxy(iX, iMaxY);
	cout << "종료\n" << endl;
	cout << "\t이동: 화살표키\t결정: SPACE BAR\n" << endl;
	cout << "===========================================================================================" << endl;
	iSelect = m_Control.Draw_Arrow(iX - 2, iY, iY, iMaxY);
	switch (iSelect)
	{
	case 0:
		m_pPlayer->Make_Player();
		break;
	case 1:
		Load_File();
		break;
	case 2:
		return iSelect;
	default:
		break;
	}
}

void CMainGame::Load_File()
{
	system("cls");
	FILE* Load_File(nullptr);
	errno_t err = fopen_s(&Load_File, "../Save/Save.dat", "rb");
	if (0 == err) {
		fread(m_pPlayer, sizeof(*m_pPlayer), 1, Load_File);
		fclose(Load_File);
		cout << "불러오기 성공!" << endl;
		system("pause");
	}
	else {
		cout << "불러오기 실패!\n캐릭터를 새로 생성합니다" << endl;
		system("pause");
		m_pPlayer->Make_Player();
	}
}

void CMainGame::Save_File()
{
	system("cls");
	FILE* Save_File(nullptr);
	errno_t err = fopen_s(&Save_File, "../Save/Save.dat", "wb");
	if (0 == err) {
		fwrite(m_pPlayer, sizeof(*m_pPlayer), 1, Save_File);
		fclose(Save_File);
		cout << "저장 성공!" << endl;
		system("pause");
	}
	else {
		cout << "저장 실패!" << endl;
		system("pause");
	}
}

