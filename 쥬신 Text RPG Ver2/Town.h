#pragma once
#include "Field.h"
#include "Player.h"
#include "Items.h"

class CTown : public CField
{
public:
	void Initialize(CPlayer* _Player);

	int Plaza();
	void Hospital();
	void Shop();
};

