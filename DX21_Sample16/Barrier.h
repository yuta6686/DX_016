#pragma once
#include "main.h"
#include "renderer.h"

class Barrier
{
public:
	void Initialize();
	void Terminate();
	void Update();
	void Draw();

	void SetBarr(D3DXVECTOR2 pos);
	Bar* GetBarr() { return &bar_par[0]; }

	void SetBrrPos(int num, D3DXVECTOR2 pos) { bar_par[num].Position = pos; }

	int GetBarNumMax() { return BAR_NUM_MAX; }

	int GetBarTexture() { return m_BarTexture; }

	bool PlayerDistance(int i, D3DXVECTOR2 plyaer_pos);

	float add_x;



private:
	int m_BarTexture;
	char TEX_NAME[128] = "data/TEXTURE/eeen.png";

	static const int BAR_NUM_MAX = 5;
	int m_bar_num = 0;

	const float add_angle = 1.0f;

	Bar bar_par[BAR_NUM_MAX];
};

