#pragma once

#define ����_������ 0
#define ����_���� 1

class CItems
{
public:
	CItems();
public:
	void Initialize();

	char* Get_ItemName();
	int Get_BonusAtk();
	int Get_BonusDef();
	int Get_BonusHp();
	int Get_BonusMp();
protected:
	char m_szItemName[16];
	int m_iBonusAtk;
	int m_iBonusDef;
	int m_iBonusHp;
	int m_iBonusMp;
	int m_iClass_Type;
};

