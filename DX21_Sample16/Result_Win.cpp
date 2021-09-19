#include "Result_Win.h"
#include "Texture.h"
#include "sprite.h"


void Result_Win::RWinInit()
{
	for (int i = 0; i < STAGE_NUM_MAX; i++)
		Result_Texture[i] = LoadTexture(RESULT_TEX_NAME[i]);

	for (int i = 0; i < SC_MAX; i++)
		PAB_Texture[i] = LoadTexture(PAB_TEX_NAME[i]);

	alpha = 0.0f;
	size = 0.0f;
}

void Result_Win::RWinUninit()
{
}

void Result_Win::RWinUpdate()
{	
	//アルファの点滅処理
	{
		if (alpha >= 180.0)alpha = 0.0f;
		else alpha += 1.0f;
	}

	//サイズの大小処理
	{
		size = sinf(alpha * RADIAN) * 300.0f;
	}
}

void Result_Win::RWinDraw()
{
	//stage_num_によって変わる背景画像処理
	{
		DrawSprite(Result_Texture[stage_num_], SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER, SCREEN_WIDTH, SCREEN_HEIGHT,
			0.0f, 0.0f, 1.0f, 1.0f);
	}

	//PressAnyButtonの描画処理
	{
		DrawSpriteColor(PAB_Texture[SC_PAB], SCREEN_WIDTH_CENTER, 300.0f+ SCREEN_HEIGHT_CENTER,
			SCREEN_WIDTH / 2 + size, SCREEN_HEIGHT / 8 + size / 4,
			0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, sinf(alpha * RADIAN)));
	}

	//NextStageの描画処理
	{
		DrawSpriteColor(PAB_Texture[SC_NEXT_STAGE], SCREEN_WIDTH_CENTER, 100.0f+ SCREEN_HEIGHT_CENTER,
			SCREEN_WIDTH / 2 + size, SCREEN_HEIGHT / 8 + size / 4,
			0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 5.0f));
	}

	//StageCrearの描画処理
	{
		DrawSpriteColor(PAB_Texture[SC_STAGE_CLEAR], SCREEN_WIDTH_CENTER, -200.0f+ SCREEN_HEIGHT_CENTER,
			SCREEN_WIDTH + size, SCREEN_HEIGHT / 2 + size / 4,
			0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
}

void Result_Win::DrawStageNum_000()
{
}

void Result_Win::DrawStageNum_001()
{
}

void Result_Win::DrawStageNum_002()
{
}
