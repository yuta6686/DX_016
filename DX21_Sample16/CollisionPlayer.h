#pragma once

#include "main.h"
#include "renderer.h"
#include "player.h"
#include "enemy.h"

class PlayerColl {
public:
	void PlayerCollEnemyUpdate();

	bool PlayerCollEnemy(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, D3DXVECTOR2 size1, D3DXVECTOR2 size2);

	int CollitionEnemy(D3DXVECTOR2 pos, D3DXVECTOR2 size);
	void SetEnemy(EnemyPrm* enemy) { enemy_ = enemy; }
	void SetPlayer(Player* player) { player_ = player->GetPlayer(); }

	void SetInitNum(int num) { InitNum_ = num; }
private:
	EnemyPrm* enemy_;
	Player_str* player_;

	int InitNum_;
};