#include "Goal.h"
#include "texture.h"
#include "sprite.h"

void Goal::Initialize()
{
	GoalTexture = LoadTexture(GOAL_TEX_NAME);
	itm.Position.x = itm.Position.y = 0.0f;
	itm.Size.x = itm.Size.y = 200.0f;
	itm.Use = false;
	itm.Frame = 0;

	GoalEffectTexture = LoadTexture(GOAL_EFFECT_TEX_NAME);
	eff.Position.x = eff.Position.y = 0.0f;
	eff.Size = D3DXVECTOR2(500.0f, 500.0f);
	eff.Use = false;
	eff.Frame = 0;

	counter = 0;
}

void Goal::Terminate()
{
}

void Goal::Update()
{
	if (eff.Frame >= EFF_X_NUM * EFF_Y_NUM) {
		eff.Frame = 0;
		//eff.use = false;
	}
	else {
		if (counter >= 1) {
			eff.Frame++;
			counter = 0;
		}
		else counter++;

	}
}

void Goal::Draw()
{

	if (itm.Use) {
		DrawSprite(GoalTexture,itm.Position.x, itm.Position.y,
			itm.Size.x, itm.Size.y,
			0.0f, 0.0f, 1.0f, 1.0f);
	}

	if (eff.Use) {
		DrawSprite(GoalEffectTexture,
			eff.Position.x, eff.Position.y, eff.Size.x, eff.Size.y,
			eff.Frame % EFF_X_NUM * EFF_WIDTH,
			eff.Frame / EFF_Y_NUM * EFF_HEIGHT,
			EFF_WIDTH,
			EFF_HEIGHT);
	}
}

void Goal::SetItem(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	if (itm.Use == false) {
		itm.Position = pos;
		itm.Size = size;
		itm.Use = true;
		itm.Frame = 0;
	}

	if (eff.Use == false) {
		eff.Position = pos;
		eff.Use = true;
		eff.Frame = 0;
	}
}

bool Goal::Collition(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	float player_r = pow((size.y / 2 + size.x / 2) / 2, 2);
	float goal_r = pow((itm.Size.x / 2 + itm.Size.y / 2) / 2, 2);
	float dist = pow((pos.x - itm.Position.x), 2) + pow((pos.y - itm.Position.y), 2);
	if (player_r + goal_r >= dist)return true;
    return false;
}
