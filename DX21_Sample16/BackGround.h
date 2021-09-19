#pragma once
#include "main.h"
#include "renderer.h"

#define BG_SPEED 1.0f;
#define BG_INIT_POS_X SCREEN_WIDTH * 2.0f

class BackGround
{
	D3DXVECTOR2 bg_pos;
	bool stop;

	int bg_monster;
	char TEX_NAME[128] = "data/TEXTURE/apace_monster.png";

	int bg_Texture;
	char BG_TEX_NAME[128] = "data/TEXTURE/node_001.png";

	D3DXVECTOR2 bg_monster_pos;
	float y_wave;
	float x_wave;

	int stage_num;

	float HitStop_;

public:
	void Initialize();
	void Terminate();
	void Update();
	void Draw();

	D3DXVECTOR2 GetBGPos() { return bg_pos; }
	void SetBGPosX(float posx) { bg_pos.x = posx; }

	void SetStop(bool flag) { stop = flag; }
	void SetStageNum(int num) { stage_num = num; }

	void SetHitStop(float value) { HitStop_ = value; }
};

