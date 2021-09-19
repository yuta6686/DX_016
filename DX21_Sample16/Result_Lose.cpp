#include "Result_Lose.h"
#include "texture.h"
#include "sprite.h"
void Result_Lose::RLoseInit()
{
	RLose_Texture = LoadTexture(TEX_NAME);

	YD_Texture = LoadTexture(YD_TEX_NAME);

	RLF_Texture = LoadTexture(RLF_TEX_NAME);

	PAB_Texture = LoadTexture(PAB_TEX_NAME);

	size = 0.0f;
	alpha = 0.0f;

	yd_width = 0.0f;
	yd_width_max = false;

	rlf_width = 0.0f;
}

void Result_Lose::RLoseUninit()
{
}

void Result_Lose::RLoseUpdate()
{
	if (yd_width >= SCREEN_WIDTH / 2) {
		yd_width = SCREEN_WIDTH / 2;
		yd_width_max = true;
	}
	else {
		yd_width += 50.0f;
	}

	if (yd_width_max) {
		if (alpha >= 180.0f) {
			alpha = 0.0f;
		}
		else {
			alpha += 1.0f;
		}

		size = sinf(alpha * RADIAN);
	}

	if (rlf_width >= SCREEN_WIDTH) {
		rlf_width = SCREEN_WIDTH;

	}
	else {
		rlf_width += 100.0f;
	}
}

void Result_Lose::RLoseDraw()
{
	
	DrawSpriteColor(RLose_Texture,SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER, SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));

	DrawSpriteColor(RLF_Texture, SCREEN_WIDTH_CENTER, -200.0f+ SCREEN_HEIGHT_CENTER,
		rlf_width, 395.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	DrawSpriteColor(YD_Texture, SCREEN_WIDTH_CENTER, -200.0f+ SCREEN_HEIGHT_CENTER,
		yd_width + size, SCREEN_HEIGHT / 4 + size * 2,
		0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, sinf(alpha * RADIAN)));

	DrawSpriteColor(PAB_Texture, SCREEN_WIDTH_CENTER, 100.0f+ SCREEN_HEIGHT_CENTER,
		yd_width + size + 200.0f, SCREEN_HEIGHT / 2 + size * 2,
		0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(1.0f, 1.0f, 1.0f, sinf(alpha * RADIAN)));
}
