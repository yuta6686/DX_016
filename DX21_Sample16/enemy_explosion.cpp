#include "enemy_explosion.h"
#include "texture.h"
#include "sprite.h"

void Enemy_Explosion::Init()
{
	EEPTexture = LoadTexture(EEP_TEX_NAME);

	for (int i = 0; i < ENEMY_NUM_MAX; i++) {
		eep[i].Frame = 0;
		eep[i].Size = D3DXVECTOR2(400.0f, 200.0f);
		eep[i].Position = D3DXVECTOR2(0.0f, 0.0f);
		eep[i].Use = false;
	}
}

void Enemy_Explosion::Uninit()
{
}

void Enemy_Explosion::Update()
{
	for (int i = 0; i < ENEMY_NUM_MAX; i++) {
		if (eep[i].Use) {
			if (eep[i].Frame >= EEXPLOSION_X_NUM * EEXPLOSION_Y_NUM) {
				eep[i].Frame = 0;
				eep[i].Use = false;
			}
			else {
				eep[i].Frame++;
				eep[i].Size.x += 20.0f;
				eep[i].Size.y += 10.0f;
			}
		}
	}
}

void Enemy_Explosion::Draw()
{
	for (int i = 0; i < ENEMY_NUM_MAX; i++) {
		if (eep[i].Use) {
			DrawSpriteColor(EEPTexture,eep[i].Position.x, eep[i].Position.y, eep[i].Size.x, eep[i].Size.y,
				eep[i].Frame % EEXPLOSION_X_NUM * EEXPLOSION_WIDTH,
				eep[i].Frame / EEXPLOSION_Y_NUM * EEXPLOSION_HEIGHT,
				EEXPLOSION_WIDTH,
				EEXPLOSION_HEIGHT,
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}

void Enemy_Explosion::Set(D3DXVECTOR2 pos)
{
	for (int i = 0; i < ENEMY_NUM_MAX; i++) {
		if (eep[i].Use == false) {
			eep[i].Frame = 0;
			eep[i].Size = D3DXVECTOR2(400.0f* SCREEN_SIZE, 200.0f* SCREEN_SIZE);
			eep[i].Position = pos;
			eep[i].Use = true;
			break;
		}
	}
}
