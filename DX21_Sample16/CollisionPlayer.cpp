//#include "CollisionPlayer.h"
//#include "enemy.h"
//
//void PlayerColl::PlayerCollEnemyUpdate()
//{
//		// 敵と操作キャラ(BB)
//	if (player_->Use == true)
//	{
//		for (int i = 0; i < ENEMY_NUM_MAX; i++)
//		{
//			if (enemy_[i].use == false)
//				continue;
//
////			if (CollisionBB(player->pos, enemy[i].pos, D3DXVECTOR2(player->w, player->h), D3DXVECTOR2(enemy[i].w, enemy[i].h)))
//			if (PlayerCollEnemy(player_->Position, enemy_[i].emp.Position,
//				player_->Size, enemy_[i].emp.Size))
//			{
//				// 操作キャラクターは死に
//
//				// 敵キャラクターは倒される
//				enemy_[i].use = false;
//
//				// HP減少処理
//
//			}
//		}
//	}
//	//エネミーとの衝突判定
//	int enemy_coll_num = CollitionEnemy(player_->Position, player_->Size);
//
//	//バレットとの衝突判定
//	//int bul_coll_num = enemy_.bln.Collision(player_.GetPlayerPos(), player_.GetPlayerSize());
//
//}
//
//bool PlayerColl::PlayerCollEnemy(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, D3DXVECTOR2 size1, D3DXVECTOR2 size2)
//{
//	
//	D3DXVECTOR2 min1, max1;
//	D3DXVECTOR2 min2, max2;
//
//	min1.x = pos1.x - size1.x / 2;
//	min1.y = pos1.y - size1.y / 2;
//	max1.x = pos1.x + size1.x / 2;
//	max1.y = pos1.y + size1.y / 2;
//
//	min2.x = pos2.x - size2.x / 2;
//	min2.y = pos2.y - size2.y / 2;
//	max2.x = pos2.x + size2.x / 2;
//	max2.y = pos2.y + size2.y / 2;
//
//	//X軸の判定
//	if (min1.x < max2.x && max1.x > min2.x)
//	{
//		//Y軸の判定
//		if (min1.y < max2.y && max1.y > min2.y)
//		{
//			//全ての条件がTRUEならヒット判定
//			return true;
//		}
//	}
//	return false;
//}
//
//int PlayerColl::CollitionEnemy(D3DXVECTOR2 pos, D3DXVECTOR2 size)
//{
//	
//	for (int j = 0; j < InitNum_; j++) {
//		if (!enemy_[j].use) break;
//
//		float player_r = pow((size.y / 2 + size.x / 2) / 2, 2);
//		float goal_r = pow((enemy_[j].emp.Size.x / 2 + enemy_[j].emp.Size.y / 2) / 2, 2);
//		float dist = pow((pos.x - enemy_[j].emp.Position.x), 2) 
//			+ pow((pos.y - enemy_[j].emp.Position.y), 2);
//
//		if (player_r + goal_r >= dist)
//			return j;
//	}
//	
//	return -1;
//}
