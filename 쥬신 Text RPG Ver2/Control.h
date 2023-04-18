#pragma once

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

class CControl
{
public:
	void CursorView(bool _timing = false) const;
	int Draw_Arrow(int iX, int iY, int iMinY = 0, int iMaxY = 0) const;
	int Control() const;
	void gotoxy(int x, int y) const;
private:
};