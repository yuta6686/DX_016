#pragma once
#include "main.h"
#include "Stage.h"

enum StageClear {
	SC_PAB,
	SC_NEXT_STAGE,
	SC_STAGE_CLEAR,
	SC_MAX,
};

class Result_Win
{
public:
	void RWinInit();
	void RWinUninit();
	void RWinUpdate();
	void RWinDraw();

	void SetStageNum(int num) { stage_num_ = num; }

private:
	int stage_num_;

	float alpha;

	float size;

	int Result_Texture[STAGE_NUM_MAX];
	char RESULT_TEX_NAME[STAGE_NUM_MAX][128] = {
		"data/TEXTURE/Result_1.png",
		"data/TEXTURE/Result_1.png",
		"data/TEXTURE/Result_1.png"
	};

	int PAB_Texture[SC_MAX];
	char PAB_TEX_NAME[SC_MAX][128] = {
		"data/TEXTURE/PressAnyButton_001.png",
		"data/TEXTURE/NextStage.png",
		"data/TEXTURE/StageClear.png"
	};

	void DrawStageNum_000();
	void DrawStageNum_001();
	void DrawStageNum_002();
};

