#pragma once
#include "main.h"
#include "Item.h"

#define EFF_X_NUM (5)
#define EFF_Y_NUM (6)

#define EFF_WIDTH	(float)(1.0f / EFF_X_NUM)
#define EFF_HEIGHT  (float)(1.0f / EFF_Y_NUM)

class Goal :
    public Item
{
public:
	virtual void Initialize()override;
	virtual void Terminate()override;
	virtual void Update()override;
	virtual void Draw()override;

	virtual void SetItem(D3DXVECTOR2 pos, D3DXVECTOR2 size)override;
	virtual bool Collition(D3DXVECTOR2 pos, D3DXVECTOR2 size)override;

	bool GetGoalUse() { return itm.Use; }

private:

	int GoalTexture;
	char GOAL_TEX_NAME[128] = "data/TEXTURE/bar.png";

	int GoalEffectTexture;
	char GOAL_EFFECT_TEX_NAME[128] = "data/TEXTURE/pppp_001.png";

	ItemPrm itm;
	ItemPrm eff;

	int counter;
};

