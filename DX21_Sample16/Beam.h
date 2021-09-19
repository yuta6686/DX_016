#pragma once
#include "main.h"
class Beam
{
public:
	void Initialize();
	void Terminate();
	void Update();
	void Draw();

	bool CollBeam(D3DXVECTOR2 pos, D3DXVECTOR2 size);	//BeamÇÃUpdateÇÊÇËÇ‡å„ÇÎÇÃèàóùÇ≈égóp
	void SetBeam(D3DXVECTOR2 pos, float angle);
	void SetPos(D3DXVECTOR2 pos) {
		if (use_) {
			//pos_.x = pos.x + size_.x / 2;
			pos_.y = pos.y;
		}
	}
	void SetBeamCoord(float x, float y, float width, float height, float tx, float ty, float tw, float th, float angle);
private:
	int BeamTexture;
	char BEAM_TEX_NAME[128] = "data/TEXTURE/beam2.png";

	D3DXVECTOR2 pos_;
	D3DXVECTOR2 size_;
	float uv_x_;
	float angle_;
	int frame_;
	bool use_;

	D3DXVECTOR2 Coordinate[4];

};

