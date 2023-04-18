#include "pch.h"
#include "Control.h"

// Ŀ�� �����
void CControl::CursorView(bool _timing) const
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = _timing; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


// ȭ��ǥ ��ġ �ű��
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


// ȭ��ǥ �Է� �ޱ�
int CControl::Control() const
{
	int Key(0);
	while (true) {
		// ȭ��ǥ Ű�� ������ 224�� ���⿡ ���� ���� �Է� �ǹǷ� �ѹ��� _getch()�� �Ѵ�.
		Key = _getch();
		if (224 == Key) {
			Key = _getch();
			return Key;
		}
		else if (SPACE == Key)
			return Key;
	}
}

// Ŀ�� ��ġ �̵� �Լ�
void CControl::gotoxy(int x, int y) const
{
	COORD posXY = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}
