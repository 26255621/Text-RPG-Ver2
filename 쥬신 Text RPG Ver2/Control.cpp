#include "pch.h"
#include "Control.h"

// 커서 숨기기
void CControl::CursorView(bool _timing) const
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = _timing; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


// 화살표 위치 옮기기
int CControl::Draw_Arrow(int iX, int iY, int iMinY, int iMaxY) const
{
	gotoxy(iX, iY);
	cout << ">";
	while (true) {
		int Key = Control();

		switch (Key)
		{
		case UP:
			if (iMinY < iY) {
				gotoxy(iX, iY);
				cout << " ";
				--iY;
				gotoxy(iX, iY);
				cout << ">";
			}
			break;
		case DOWN:
			if (iMaxY > iY) {
				gotoxy(iX, iY);
				cout << " ";
				++iY;
				gotoxy(iX, iY);
				cout << ">";
			}
			break;
		case SPACE:
			return (iY - iMinY);
		default:
			break;
		}
	}
}


// 화살표 입력 받기
int CControl::Control() const
{
	int Key(0);
	while (true) {
		// 화살표 키를 누르면 224와 방향에 따른 수가 입력 되므로 한번더 _getch()를 한다.
		Key = _getch();
		if (224 == Key) {
			Key = _getch();
			return Key;
		}
		else if (SPACE == Key)
			return Key;
	}
}

// 커서 위치 이동 함수
void CControl::gotoxy(int x, int y) const
{
	COORD posXY = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}
