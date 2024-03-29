//=============================================================================
//
// 当たり判定処理 [collision.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "collision.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"


//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// 構造体定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, D3DXVECTOR2 size1, D3DXVECTOR2 size2);
bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, float size1, float size2);


//*****************************************************************************
// グローバル変数
//*****************************************************************************


//=============================================================================
// 当たり判定処理
//=============================================================================
void UpdateCollision(void)
{
	PLAYER *player = GetPlayer();		// プレイヤーのポインターを初期化
	ENEMY  *enemy = GetEnemy();		// エネミーのポインターを初期化
	BULLET *bullet = GetBullet();		// バレットのポインターを初期化

	// 敵と操作キャラ(BB)
	if (player[0].use == true)
	{
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (enemy[i].use == false)
				continue;

//			if (CollisionBB(player->pos, enemy[i].pos, D3DXVECTOR2(player->w, player->h), D3DXVECTOR2(enemy[i].w, enemy[i].h)))
			if (CollisionBC(player->pos, enemy[i].pos, player->h/2, enemy[i].h/2))
			{
				// 操作キャラクターは死に

				// 敵キャラクターは倒される
				enemy[i].use = false;

				// HP減少処理

			}
		}
	}

	// 弾と敵(BB)
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i].use == false)
			continue;

		for (int j = 0; j < ENEMY_MAX; j++)
		{
			if (enemy[j].use == false)
				continue;
				
			if (CollisionBB(bullet[i].pos, enemy[j].pos, D3DXVECTOR2(bullet[i].w, bullet[i].h), D3DXVECTOR2(enemy[j].w, enemy[j].h)))
			{
				bullet[i].use = false;		// 弾の消滅処理を行い
				enemy[j].use = false;		// 敵は倒される

				// スコア計算

				//break;					// １回当たって終わりの時はここでbreakする。１フレーム内の間有効ならbreakをコメントにする。
			}
		}
	}

	// ボスと弾(BC)

	// 自分と敵の弾(BC)

	// 死亡したら状態遷移

}

//=============================================================================
// BBによる当たり判定処理
// 回転は考慮しない
// 戻り値：当たってたらtrue
//=============================================================================
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, D3DXVECTOR2 size1, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, max1;
	D3DXVECTOR2 min2, max2;

	min1.x = pos1.x - size1.x / 2;
	min1.y = pos1.y - size1.y / 2;
	max1.x = pos1.x + size1.x / 2;
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x - size2.x / 2;
	min2.y = pos2.y - size2.y / 2;
	max2.x = pos2.x + size2.x / 2;
	max2.y = pos2.y + size2.y / 2;

	//X軸の判定
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Y軸の判定
		if (min1.y < max2.y && max1.y > min2.y)
		{
			//全ての条件がTRUEならヒット判定
			return true;
		}
	}

	return false;
}

//=============================================================================
// BCによる当たり判定処理
// サイズは半径
// 戻り値：当たってたらtrue
//=============================================================================
bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, float size1, float size2)
{
	//pos1とpos2をつなぐベクトルを作る
	D3DXVECTOR2 vDistance = pos1 - pos2;

	//vDistanceのベクトル長を得る
	float length;
//	length = D3DXVec2Length(&vDistance);
	length = D3DXVec2LengthSq(&vDistance);

//	float size = size1 + size2;
	float size = (size1 + size2) * (size1 + size2);

	//1と2の半径を足して判定する
	//差分のベクトル長の方が小さければ
	//ヒットしている
	if (length < size)
	{
		return true;
	}

	return false;
}
