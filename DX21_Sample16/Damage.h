#pragma once
#include "main.h"
enum DAMAGE_STATE {
	DAMAGE_NONE,
	DAMAGE_TAKE,
};
class Damage {
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

	void TakeDamage();
	void SetTexNum(int num) { select_tex_num = num; }
private:
	float r_;
	float g_;
	float b_;
	float a_;

	float wave;

	DAMAGE_STATE d_state;
	DAMAGE_STATE d_next;

	char TEX_NAME_000[128] = "data/TEXTURE/damage.png";
	char TEX_NAME_001[128] = "data/TEXTURE/damage1.png";
	char TEX_NAME_002[128] = "data/TEXTURE/damage2.png";
	char TEX_NAME_003[128] = "data/TEXTURE/damage3.png";

	int DTex[4];

	int select_tex_num;
};