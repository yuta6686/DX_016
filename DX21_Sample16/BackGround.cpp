#include "BackGround.h"
#include "Texture.h"
#include "sprite.h"

void BackGround::Initialize()
{
	bg_Texture = LoadTexture(BG_TEX_NAME);
	bg_monster = LoadTexture(TEX_NAME);

	bg_pos.x = BG_INIT_POS_X;
	bg_pos.y = 0.0f;
	stop = false;

	bg_monster_pos = D3DXVECTOR2(+SCREEN_WIDTH / 2, 0.0f);
}

void BackGround::Terminate()
{
}

void BackGround::Update()
{
	if (!stop) {
		if (bg_pos.x <= -BG_INIT_POS_X) {
			bg_pos.x = BG_INIT_POS_X;
		}
		else {
			bg_pos.x -= HitStop_ * BG_SPEED;
		}
	}

	if (stage_num == 2)return;
	if (y_wave >= 360.0f) {
		y_wave = 0.0f;
	}
	else {
		y_wave += 1.0f * HitStop_;
		bg_monster_pos.y = sinf(y_wave * RADIAN) * SCREEN_HEIGHT / 2;
	}

	if (x_wave >= 360.0f) {
		x_wave = 0.0f;
	}
	else {
		x_wave += 0.5f * HitStop_;
		bg_monster_pos.x = cosf(x_wave * RADIAN) * SCREEN_WIDTH / 2;
	}
}

void BackGround::Draw()
{
	DrawSpriteColor(bg_Texture,
		bg_pos.x + SCREEN_WIDTH_CENTER, bg_pos.y + SCREEN_HEIGHT_CENTER,
		SCREEN_WIDTH * 5.0f, SCREEN_HEIGHT,
		0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(HitStop_, HitStop_, HitStop_, 1.0f));

	if (stage_num == 2)return;

	DrawSpriteColor(bg_monster,
		bg_monster_pos.x + SCREEN_WIDTH_CENTER, bg_monster_pos.y + SCREEN_HEIGHT_CENTER,
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.3f));
}
