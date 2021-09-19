#pragma once
#include "main.h"
#include "renderer.h"


#define ACCELERATION 0.05f

#define JSR_X_NUM 5
#define JSR_Y_NUM 3
#define JSR_WIDTH (1.0f/JSR_X_NUM)
#define JSR_HEIGHT (1.0f/JSR_Y_NUM)


class Just_Guard
{
public:
	void Initialize(void);
	void Terminate(void);
	void Update(void);
	void Draw(void);

	void Set(D3DXVECTOR2 Pos);
	void SetPos(D3DXVECTOR2 Pos) { jsg.pos_ = Pos; }
	void SetPosR(D3DXVECTOR2 Pos) { jsgr.pos_ = Pos; }
	void SetUse(bool flag) { jsg.use_ = flag; }
	bool GetUse() { return jsg.use_; }

private:
	JSG jsg;

	int JustGuardTexture;
	char TEX_NAME[128] = "data/TEXTURE/bar.png";


	JSG jsgr;
	int JSR_Texture;
	char JSR_TEX_NAME[128] = "data/TEXTURE/JustGuard.png";

	JSG jsge;
	int JSE_Texture;
	char JSE_TEX_NAME[128] = "data/TEXTURE/JustGuardEff.png";
	float uv_;
};

