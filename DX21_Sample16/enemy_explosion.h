#pragma once

#include "main.h"
#include "renderer.h"

#define ENEMY_NUM_MAX 100

#define EEXPLOSION_X_NUM		(5)
#define EEXPLOSION_Y_NUM		(6)

#define EEXPLOSION_WIDTH		(1.0f / EEXPLOSION_X_NUM)
#define EEXPLOSION_HEIGHT	(1.0f / EEXPLOSION_Y_NUM)

struct EExp_par
{
	D3DXVECTOR2	Position;
	D3DXVECTOR2  Size;
	int		Frame;
	bool	Use;
};

class Enemy_Explosion
{
public:
	virtual void Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();
	void Set(D3DXVECTOR2 pos);
private:
	EExp_par eep[ENEMY_NUM_MAX];
	int EEPTexture;
	char EEP_TEX_NAME[128] = "data/TEXTURE/monster_exp.png";
};

