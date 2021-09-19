#include "bullet_new.h"
#include "sprite.h"
#include "texture.h"



void Bullet_new::Initialize()
{
	BulletNTexture = LoadTexture(TEX_NAME);
	for (int i = 0; i < BULLETN_NUM_MAX; i++) {
		bln[i].pos = D3DXVECTOR2(0.0f, 0.0f);
		bln[i].size = 60 * 3 / 4.0f;
		bln[i].use = false;
		bln[i].vel = D3DXVECTOR2(0.0f, 0.0f);
	}
	delay_count = 0;
}

void Bullet_new::Terminate()
{
}

void Bullet_new::Update()
{
	for (int i = 0; i < BULLETN_NUM_MAX; i++) {
		if (bln[i].use) {
			bln[i].pos.x += bln[i].vel.x * HitStop_;
			bln[i].pos.y += bln[i].vel.y * HitStop_;

			if (bln[i].pos.x <= -SCREEN_WIDTH / 2.0f ||
				bln[i].pos.x >= SCREEN_WIDTH / 2.0f ||
				bln[i].pos.y <= -SCREEN_HEIGHT / 2.0f ||
				bln[i].pos.y >= SCREEN_HEIGHT / 2.0f) {
				bln[i].use = false;
			}
		}


	}
}

void Bullet_new::Draw()
{
	for (int i = 0; i < BULLETN_NUM_MAX; i++) {
		if (bln[i].use) {
			DrawSpriteColor(BulletNTexture,bln[i].pos.x, bln[i].pos.y, bln[i].size, bln[i].size,
				0.0f, 0.0f, 1.0f, 1.0f,
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
	}
}

void Bullet_new::Set(D3DXVECTOR2 pos, D3DXVECTOR2 vel, float size)
{
	for (int i = 0; i < BULLETN_NUM_MAX; i++) {
		if (!bln[i].use)
		{
			bln[i].pos = pos;
			bln[i].size = size*3/4;
			bln[i].vel = vel;
			bln[i].use = true;
			break;
		}
	}
}


