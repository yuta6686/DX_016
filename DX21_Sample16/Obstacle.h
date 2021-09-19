#pragma once
#include "main.h"
#include "Texture.h"

#define OBS_SPEED 2.0f

class Obstacle
{
private:
	UINT m_ObsTexture;
	char TEX_NAME[128] = "data/TEXTURE/obs.png";

	static const int OBS_NUM_MAX = 100;
	int m_obs_num = 0;

	Obs obs_par[OBS_NUM_MAX];
	ObsPrm* InitPosition;
	int InitNum_;

	float HitStop_;
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

	void SetObs(D3DXVECTOR2 pos);
	void SetObs(D3DXVECTOR2 pos, D3DXVECTOR2 size);

	int ObsPlayerCollition(D3DXVECTOR2 pos, D3DXVECTOR2 size);

	void SetObsTexture() { m_ObsTexture = LoadTexture(TEX_NAME); }
	int GetObsTexture() { return m_ObsTexture; }

	Obs* GetObsPar() { return &obs_par[0]; }

	void SetInitNum(int num) { InitNum_ = num; }
	void SetInitPos(ObsPrm* inf) { InitPosition = inf; }

	void SetHitStop(float value) { HitStop_ = value; }

};

