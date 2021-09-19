//=============================================================================
//
// タイトル画面処理 [title.h]
// Author : 
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"
#include "Barrier.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TITLE_X_NUM			(5)
#define TITLE_Y_NUM			(6)

#define PARTICLE_X_NUM		(5)
#define PARTICLE_Y_NUM		(6)

#define TITLE_WIDTH			(1.0f / TITLE_X_NUM)
#define TITLE_HEIGHT		(1.0f / TITLE_Y_NUM)

#define PARTICLE_WIDTH		(1.0f / PARTICLE_X_NUM)
#define PARTICLE_HEIGHT		(1.0f / PARTICLE_Y_NUM)

#define COUNTER_MAX 1

#define SPHERE_NUM 3
#define SPHERE_NUM_MAX 20

#define DEGREE 0.1f

#define TITILE_MAX_SIZE SCREEN_WIDTH/2

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
class TitleParameter : public ParameterFrame {
public:
	bool Size_Max;
};

class Spher :public ParameterAlpha {
public:
	int pat;
	bool barrier_use;
};

class Title {
public:
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	Barrier bar_;
	TitleParameter _title;
	Spher _sph[SPHERE_NUM][SPHERE_NUM_MAX];

	int ApaceMonsterTexture;
	char AM_TEX_NAME[128] = "data/TEXTURE/monster_sculpt.png";

	int SpaceTexture;
	char SPACE_TEX_NAME[128] = "data/TEXTURE/space.png";

	int TitleTexture;
	char TITLE_TEX_NAME[128] = "data/TEXTURE/Space_Break_001.png";


	int SpherTexture[SPHERE_NUM];
	char SPHERE_TEX_NAME[SPHERE_NUM][128] = {
		"data/TEXTURE/Sphere.png",
		"data/TEXTURE/Sphere1.png",
		"data/TEXTURE/Sphere2.png"
	};
	int title_counter = 0;
	int particle_counter = 0;
	int sphere_counter = 0;

	float title_dig_rad = 0.0f;
	float sphere_dig_rad = 0.0f;
	float rotate_title_dig_rad = 0.0f;

	void SetSph(int pat, float x, float y, float size);
	void SetTitle(float x, float y);
};