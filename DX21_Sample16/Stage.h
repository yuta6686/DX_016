//=============================================================================
//
// ステージ [stage.h]
// Author : 
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"
#include "player.h"
#include "CollisionPlayer.h"
#include "enemy.h"
#include "BackGround.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Damage.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************

enum RESULT{
	WIN = 0,
	LOSE
};

#define STAGE_NUM_MAX 3
#define OBS_NUM_MAX 100
#define INVINCIBLE_TIME 180
#define SCREEN_HEIGHT_HARF (float)(SCREEN_HEIGHT/2)

//*****************************************************************************
// クラス定義
//*****************************************************************************
class Stage {
public:
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();

	int stage_num_ = 0;
	bool stage_num_flag;
	int result;

private:
	//メンバクラス宣言
	Player player_;
	Enemy enemy_;
	BackGround bg_;
	Goal goal_;
	Obstacle obs;
	Damage dmg;

	//メンバ変数
	int enemy_loop = 0;

	bool invincible;
	int invincible_count;

	bool jsg_flag;
	bool d_inv;

	bool beam_fire;
	bool boss_appear;
	bool boss_disappear;

	int beam_num;
	float hitStop;

	int enemy_coll_num = -1;
	int bullet_coll_num = -1;

	//メンバ関数
		//Initの拡張
	void SetInit();

		//Updateの拡張
	void HitStop();
	void GoalSet();
	void GoalUpdate();

	void InvincibleCount();
	void PlayerInv();
	void PlayerIsDead();


	//コリジョン更新処理
	void PlayerEnemyCollUpdate();

	//PlayerEnemyCollUpdateの拡張
	void InvincibleUpdate_Enemy();
	void JustUpdate_Enemy();
	void DeathUpdate_Enemy();

	void InvincibleUpdate_EnemyBullet();
	void JustUpdate_EnemyBullet();
	void DeathUpdate_EnemyBullet();

	void JustCounterUpdate();

	//Beam
	void ShotBeam();
//	void ShotBeam_boss();

	void EnemyCollBeam();
//	void BossCollBeam();

	//コリジョン判定
	int DudgeCollisionEnemy();
	int DudgeCollisionBullet();

	//バレットのセット
	void EnemySetBullet();
	void BossSetBullet();
	
};


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

