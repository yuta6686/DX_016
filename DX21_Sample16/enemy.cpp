//=============================================================================
//
// エネミー処理 [enemy.cpp]
// Author : 
//
//=============================================================================
#include "enemy.h"
#include "texture.h"
#include "sprite.h"
#include <stdlib.h>


//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************


//=============================================================================
// 初期化処理
//=============================================================================

HRESULT Enemy::Init()
{
	eep_.Init();
	bln.Initialize();

	rep(i, ENEMY_PATTERN_NUM) 
		EnemyTexture[i] = LoadTexture(ENEMY_TEX[i]);

	//HitStop_使用時消す
	HitStop_ = 1.0f;

	//enemy_par初期化
	for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
		for (int j = 0; j < InitNum_; j++) {
			enemy_par[i][j].emp.Position.x = 1000.0f;
			enemy_par[i][j].emp.Position.y = 1000.0f;
			enemy_par[i][j].emp.Size.x = 400.0f;
			enemy_par[i][j].emp.Size.y = 200.0f;
			enemy_par[i][j].emp.pat = 0;
			enemy_par[i][j].use = false;
			enemy_par[i][j].interval = false;
			enemy_par[i][j].frame = 0;
			enemy_par[i][j].wave_speed = 0.0f;
			enemy_par[i][j].emp.acceleration = 1.5f;

		}
	}

	for (int i = 0; i < InitNum_; i++) {
		enemy_par[InitPosition[i].pat][i].emp.Position.x = InitPosition[i].Position.x + SCREEN_WIDTH_CENTER;
		enemy_par[InitPosition[i].pat][i].emp.Position.y = InitPosition[i].Position.y + SCREEN_HEIGHT_CENTER;
		enemy_par[InitPosition[i].pat][i].emp.Size.x = InitPosition[i].Size.x * SCREEN_SIZE;
		enemy_par[InitPosition[i].pat][i].emp.Size.y = InitPosition[i].Size.y * SCREEN_SIZE;
		enemy_par[InitPosition[i].pat][i].emp.acceleration = InitPosition[i].acceleration;
		enemy_par[InitPosition[i].pat][i].emp.x_move = InitPosition[i].x_move;
		enemy_par[InitPosition[i].pat][i].emp.bullet_interval = InitPosition[i].bullet_interval ;
		enemy_par[InitPosition[i].pat][i].use = true;
	}
	
	return S_OK;
}


//=============================================================================
// 終了処理
//=============================================================================
void Enemy::Uninit()
{
	bln.Terminate();
	eep_.Uninit();
}



//=============================================================================
// 更新処理
//=============================================================================
void Enemy::Update()
{
	eep_.Update();
	bln.Update();

	rep(i, ENEMY_PATTERN_NUM) {
		rep(j, InitNum_) {
			if (!enemy_par[i][j].use)continue;
			EnemyUpdateExtend(i, j);
			EnemyUpdateExtend_001(i, j);
		}
	}
}

//=============================================================================
// 更新処理の関数化
//=============================================================================
void Enemy::EnemyUpdateExtend(int i, int j)
{
	if (enemy_par[i][j].wave_speed >= 360.0f) {
		enemy_par[i][j].wave_speed = 0.0f;
	}
	else {
		if (enemy_par[i][j].emp.acceleration != 0.0f) {
			enemy_par[i][j].wave_speed += enemy_par[i][j].emp.acceleration * HitStop_;

			enemy_par[i][j].emp.Position.y = InitPosition[i].Position.y * sinf(enemy_par[i][j].wave_speed * RADIAN) * HitStop_;
		}

		enemy_par[i][j].emp.Position.x -= enemy_par[i][j].emp.x_move * HitStop_;
	}

	if (enemy_par[i][j].emp.Position.x <= 0) {
		enemy_par[i][j].use = false;
	}
}

void Enemy::EnemyUpdateExtend_001(int i, int j)
{
	if (enemy_par[i][j].frame >= enemy_par[i][j].emp.bullet_interval + rand() % 50) {
		enemy_par[i][j].frame = 0;
		enemy_par[i][j].interval = true;
	}
	else {
		enemy_par[i][j].frame++;
	}
}



//=============================================================================
// 描画処理
//=============================================================================
void Enemy::Draw()
{
	eep_.Draw();
	bln.Draw();

	rep(i, ENEMY_PATTERN_NUM) {
		rep(j, InitNum_) {
			if (enemy_par[i][j].use) {
				DrawSprite(EnemyTexture[i], enemy_par[i][j].emp.Position.x, enemy_par[i][j].emp.Position.y,
					enemy_par[i][j].emp.Size.x, enemy_par[i][j].emp.Size.y,
					0.0f, 0.0f, 1.0f, 1.0f);
			}
		}
	}
}



//=============================================================================
// エネミー構造体の先頭アドレスを取得
//=============================================================================


