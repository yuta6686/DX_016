#pragma once
#include "main.h"
#include "renderer.h"

#define BULLETN_NUM_MAX 100
#define BULLETN_SPEED 15.0f

class Bullet_new {
public:
	void Initialize();
	void Terminate();
	void Update();
	void Draw();

	void Set(D3DXVECTOR2 pos, D3DXVECTOR2 vel, float size);
	

	void SetFalse(int i) { bln[i].use = false; }
	D3DXVECTOR2 GetPos(int i) { return bln[i].pos; }
	float GetSize(int i) { return bln[i].size; }

	bool GetUse(int i) { return bln[i].use; }

	void SetHitStop(float value) { HitStop_ = value; }
private:
	int BulletNTexture;
	char TEX_NAME[128] = "data/TEXTURE/sphere.png";

	BulN bln[BULLETN_NUM_MAX];

	float HitStop_;

	int delay_count;
};