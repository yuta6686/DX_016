/*==============================================================================

   プレイヤー処理 [player.cpp]
														 Author :Yuta Yanagisawa
														 Date   :2021/9/4
--------------------------------------------------------------------------------

==============================================================================*/
#include "player.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "bullet.h"
#include "score.h"
#include "sound.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static int	g_SENo;		// SE識別子

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT Player::Init(void)
{
	//テクスチャ読み込み
	PlayerTexture = LoadTexture(PLAYER_TEX_NAME);
	

	//初期化
	jsg.Initialize();
	beam.Initialize();
	bar.Initialize();

	player_par.Position.x = 300.0f;
	player_par.Position.y = 440.0f;
	player_par.Size.x = 200.0f;
	player_par.Size.y = 64.0f;

	g_SENo = LoadSound("data/SE/shot001.wav");
	//Playsound(BGMの番号,0～254);
	
	just = false;
	death = false;
	just_counter = 0;
	hp_ = 3;

	a_ = 1.0f;
	speed_a_ = 0.0f;

	HitStop = 1.0f;

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void Player::Uninit(void)
{
	jsg.Terminate();
	beam.Terminate();
	bar.Terminate();
}

//=============================================================================
// 更新処理
//=============================================================================
void Player::Update(void)
{
	jsg.Update();
	beam.Update();
	bar.Update();


	// 弾発射
	if (GetKeyboardTrigger(DIK_SPACE))
	{
		D3DXVECTOR2 pos = player_par.Position;
		SetBullet(pos);		// １発目
		AddScore(123);
		PlaySound(g_SENo, 0);
	}


#if 1


	/*if (coll != -1) {

		coll_size_y = obs->GetObsPar()[coll].opm.size.y;
		coll_size_x = obs->GetObsPar()[coll].opm.size.x + 50.0f;
	}*/


	// ボタン
	if (coll == -1) {
		if (GetKeyboardPress(DIK_A))
			player_par.Position.x -= PLAYER_SPEED * 2.0f * HitStop;
	}
	else { player_par.Position.x += PLAYER_SPEED * 2.5f * HitStop; }

	if (coll == -1) {
		if (GetKeyboardPress(DIK_D))
			player_par.Position.x += PLAYER_SPEED * HitStop;
	}
	else { player_par.Position.x -= (PLAYER_SPEED * 2.5f) * HitStop; }
	//else { player_par.Position.x -= (PLAYER_SPEED * 2.5f + OBS_SPEED) * HitStop; }
	// ボタン


	if (coll == -1) {
		if (GetKeyboardPress(DIK_S))
			player_par.Position.y += PLAYER_SPEED * HitStop;
	}

	if (GetKeyboardPress(DIK_W)) {
		g_rise_flag = true;

		g_fall_flag = false;

	}
	else {
		g_rise_flag = false;

		g_fall_flag = true;

	}

	if (g_fall_flag) {
		//if (coll != -1 && player_par.Position.y < obs->GetObsPar()[coll].opm.pos.y) {
			//player_par.pos.y = obs.GetObsPar()[coll].pos.y - coll_size_y;
			//g_fall_flag = false;
		//}
		//else {
			g_speed.fall += g_a.fall * HitStop;
			player_par.Position.y += g_speed.fall * HitStop;
		//}
	}
	else {
		g_speed.fall = PLAYER_SPEED;
	}

	if (g_rise_flag) {
		//if (coll != -1 && player_par.Position.y > obs->GetObsPar()[coll].opm.pos.y) {
		//	//player_par.pos.y = obs.GetObsPar()[coll].pos.y + coll_size_y;
		//	g_rise_flag = false;
		//}
		//else {
			g_speed.rise -= g_a.rise * HitStop;
			player_par.Position.y -= g_speed.rise * HitStop;
		//}
	}
	else {
		g_speed.rise = PLAYER_SPEED;
	}
#endif 

	ThunderUpdate();
	ReflectionUpdate();

	if (player_par.Position.x < 0.0f)
		player_par.Position.x = 0.0f;

	if (player_par.Position.x > SCREEN_WIDTH)
		player_par.Position.x = SCREEN_WIDTH;

	if (player_par.Position.y < -SCREEN_HEIGHT)
		player_par.Position.y = -SCREEN_HEIGHT;

}

void Player::ThunderUpdate()
{
	//for (int i = 0; i < THUNDER_NUM_MAX; i++) {
	//	if (!thu.GetThuUse(i)) {
	//		if (GetControllerPress(NpadButton::X::Index)) {
	//			if (thu.GetThuFrame(i) == 0) {
	//				thu.SetThunder(player_par.pos);
	//			}

	//		}
	//	}
	//	else {
	//		thu.SetThunderPos(i, player_par.pos);
	//	}
	//}

	//thu.ThunderUpdate();
}
void Player::ReflectionUpdate()
{
	//if (GetControllerTrigger(NpadButton::R::Index)) {
	//	ref.SetRef(player_par.pos);
	//}
	//else {
	//	ref.SetRefSizePos(MakeFloat2(player_par.pos.x - (500.0f * sinf(ref.GetAngle() * RADIAN)), player_par.pos.y));
	//}

	//shi.SetPos(player_par.pos);
}
//=============================================================================
// 描画処理
//=============================================================================
void Player::Draw(void)
{
	jsg.Draw();
	beam.Draw();
	bar.Draw();

	DrawSprite(PlayerTexture, player_par.Position.x,
		player_par.Position.y, player_par.Size.x,
		player_par.Size.y, 0.0f, 0.0f, 1.0f, 1.0f);
}

//=============================================================================
// プレイヤー構造体の先頭アドレスを取得
//=============================================================================
Player_str* Player::GetPlayer(void)
{
	return &player_par;
}

