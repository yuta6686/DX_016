#pragma once
#include "main.h"

class Result_Lose
{
public:
	void RLoseInit();
	void RLoseUninit();
	void RLoseUpdate();
	void RLoseDraw();

	void SetStageNum(int num) { stage_num_ = num; }

private:
	int stage_num_;
	float size;
	float alpha;

	int RLose_Texture;
	char TEX_NAME[128] = "data/TEXTURE/smoke.png";

	int YD_Texture;
	char YD_TEX_NAME[128] = "data/TEXTURE/Youdied.png";
	float yd_width;
	bool yd_width_max;

	int RLF_Texture;
	char RLF_TEX_NAME[128] = "data/TEXTURE/RLoseFlame.png";
	float rlf_width;

	int PAB_Texture;
	char PAB_TEX_NAME[128] = "data/TEXTURE/PressAnyButton_Lose.png";
};

