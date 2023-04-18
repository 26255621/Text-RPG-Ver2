#pragma once

typedef struct tagStat {
	char m_szName[16];
	int m_iExtraAtk, m_iAtk;
	int m_iExtraDef, m_iDef;
	int m_iExtraHp, m_iMAxHp, m_iHp;
	int m_iExtraMp, m_iMaxMp, m_iMp;
}STAT, *PSTAT;