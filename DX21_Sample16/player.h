/*==============================================================================

   頂点管理[player.h]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once


#include "main.h"
#include "renderer.h"
#include "player.h"
#include "collision.h"
#include "Just_Guard.h"
#include "Beam.h"
#include "Obstacle.h"
#include "Barrier.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define PLAYER_DOWN_LIMIT SCREEN_HEIGHT / 2
#define PLAYER_SPEED 2.5f
#define PLAYER_MOVE 5.0f
#define PLAYER_ACCELERATION_RISE 0.125f
#define PLAYER_ACCELERATION_FALL 0.125f


// プレイヤー構造体
struct Player_str {
	D3DXVECTOR2 Position;
	D3DXVECTOR2 Size;
	D3DXVECTOR2 vel;
};


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
class Player {
public:
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	D3DXVECTOR2 GetPlayerPos() { return player_par.Position; }
	D3DXVECTOR2 GetPlayerSize() { return player_par.Size; }

	int GetHP() { return hp_; }
	void AddHP() { hp_++; }
	void RedHP() { hp_--; }
	bool Dead() { return (hp_ <= 0); }

	void Damage();

	void SetPos(D3DXVECTOR2 pos) { player_par.Position = pos; }

	Player_str* GetPlayer(void);

	Player_str player_par;

	Just_Guard jsg;

	Beam beam;
	Barrier bar;

	bool just;
	bool death;

	int just_counter;
	int coll;

	bool invincible_;

	void SetHitStop(float value) { HitStop = value; }

	void SetObs(Obstacle* obs_) { obs = obs_; }


private:

	int PlayerTexture;
	char PLAYER_TEX_NAME[128] = "data/TEXTURE/space_ship.png";

	bool g_rise_flag;
	bool g_fall_flag;

	struct  g_player_vertical {
		float fall;
		float rise;
	};

	g_player_vertical g_a = { PLAYER_ACCELERATION_FALL,-PLAYER_ACCELERATION_RISE };
	g_player_vertical g_speed = { PLAYER_MOVE ,-PLAYER_SPEED };

	int hp_;

	float a_;
	float speed_a_;

	float coll_size_y = 0.0f;
	float coll_size_x = 0.0f;

	float HitStop;

	void ThunderUpdate();
	void ReflectionUpdate();


	Obstacle* obs;
};

