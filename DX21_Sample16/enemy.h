//=============================================================================
//
// エネミー処理 [enemy.h]
// Author : 
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"
#include "enemy_explosion.h"
#include "Bullet_new.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define ENEMY_PATTERN_NUM 3
#define ENEMY_NUM_MAX 100

// エネミー構造体
class EnemyPrm
{
public:
	MovePrm emp;
	bool use;
	int frame;
	bool interval;
	float wave_speed;
	
};


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// クラス定義
//*****************************************************************************

class Enemy {
public:
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();


	Enemy_Explosion eep_;
	Bullet_new bln;

	EnemyPrm enemy_par[ENEMY_PATTERN_NUM][ENEMY_NUM_MAX]; 
	
	void SetInitNum(int initnum) { InitNum_ = initnum; }
	void SetHitStop(float value) { HitStop_ = value; }

	void SetInitPos(MovePrm* InitPos) { InitPosition = InitPos; }
	void SetStageNum(int stagenum) { stage_num = stagenum; }

	void SetUse(int j, bool flag) {
		for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
			enemy_par[i][j].use = flag;
		}
	}

	D3DXVECTOR2 GetEnemyPos(int j) {
		for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
			if (enemy_par[i][j].use)
				return enemy_par[i][j].emp.Position;
		}
		return D3DXVECTOR2(-1000.0f, 0.0f);
	}

	D3DXVECTOR2 GetEnemySize(int j) {
		for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
			if (enemy_par[i][j].use) {
				return enemy_par[i][j].emp.Size;
			}
		}
	}
private:
	char ENEMY_TEX[ENEMY_PATTERN_NUM][128] = {
		"data/TEXTURE/monster_001.png",
		"data/TEXTURE/monster_002.png",
		"data/TEXTURE/monster_003.png"
	};

	int EnemyTexture[ENEMY_PATTERN_NUM];
	int InitNum_;
	int stage_num;

	float HitStop_;

	MovePrm* InitPosition;

	//メンバ関数
	void EnemyUpdateExtend(int i, int j);
	void EnemyUpdateExtend_001(int i, int j);
};