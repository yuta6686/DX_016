#include "Beam.h"
#include "texture.h"
#include "sprite.h"

void Beam::Initialize()
{
	BeamTexture = LoadTexture(BEAM_TEX_NAME);

	{//init param
		pos_ = D3DXVECTOR2(0.0f, 0.0f);
		size_ = D3DXVECTOR2(0.0f, 424.0f*3/4);
		uv_x_ = 0.0f;
		angle_ = 0.0f;
		frame_ = 0;
		use_ = false;
	}

}

void Beam::Terminate()
{
}

void Beam::Update()
{
	if (use_) {
		if (uv_x_ >= 1.0f) {
			uv_x_ = 1.0f;
			use_ = false;
		}
		else {
			uv_x_ += 0.05f;
		}

		if (size_.x >= 1920.0f) {
			size_.x = 0.0f;
		}
		else {
			size_.x += 1920.0f * 0.05f;
		}
		//pos_.x -=1920.0f * 0.05f;

		SetBeamCoord(pos_.x, pos_.y, size_.x, size_.y, 0.0f, 0.0f, uv_x_, 1.0f, angle_);

	}
}

void Beam::Draw()
{
	if (use_) {
		DrawSpriteRotate_Beam(BeamTexture,pos_.x, pos_.y, size_.x, size_.y, 0.0f, 0.0f, uv_x_, 1.0f, angle_,
			D3DXCOLOR(0.7f, 1.0f, 1.0f, 1.0f));

		/*DrawSpriteColor(BeamTexture, pos_.x, pos_.y, size_.x, size_.y, 0.0f, 0.0f, uv_x_, 1.0f,
			D3DXCOLOR(0.7f, 1.0f, 1.0f, 1.0f));*/
	}
}

void Beam::SetBeam(D3DXVECTOR2 pos, float angle) {
	if (!use_) {
		pos_.x = pos.x + (size_.x / 2);
		angle_ = angle;
		use_ = true;
		frame_ = 0;
		uv_x_ = 0.0f;
	}
}

void Beam::SetBeamCoord(float x, float y, float width, float height, float tx, float ty, float tw, float th, float angle)
{
	height /= 4;

	float hw, hh;
	hw = width * 0.5f;
	hh = height * 0.5f;

	float rad = RADIAN * angle;

	float rot_x = +hw * 2.0f;
	float rot_y = -hh;

	Coordinate[0] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + x,
		rot_x * sinf(rad) + rot_y * cosf(rad) + y);


	rot_x = 0.0f;
	rot_y = -hh;
	Coordinate[1] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + x,
		rot_x * sinf(rad) + rot_y * cosf(rad) + y);

	rot_x = +hw * 2.0f;
	rot_y = +hh;
	Coordinate[3] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + x,
		rot_x * sinf(rad) + rot_y * cosf(rad) + y);

	rot_x = 0.0f;
	rot_y = +hh;
	Coordinate[2] = D3DXVECTOR2(rot_x * cosf(rad) - rot_y * sinf(rad) + x,
		rot_x * sinf(rad) + rot_y * cosf(rad) + y);


}

bool Beam::CollBeam(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	if (use_) {
		if (((Coordinate[1].x - Coordinate[0].x) * (pos.y - Coordinate[0].y)) -
			((pos.x - Coordinate[0].x) * (Coordinate[1].y - Coordinate[0].y)) <= 0 &&

			((Coordinate[2].x - Coordinate[1].x) * (pos.y - Coordinate[1].y)) -
			((pos.x - Coordinate[1].x) * (Coordinate[2].y - Coordinate[1].y)) <= 0 &&

			((Coordinate[3].x - Coordinate[2].x) * (pos.y - Coordinate[2].y)) -
			((pos.x - Coordinate[2].x) * (Coordinate[3].y - Coordinate[2].y)) <= 0 &&

			((Coordinate[0].x - Coordinate[3].x) * (pos.y - Coordinate[3].y)) -
			((pos.x - Coordinate[3].x) * (Coordinate[0].y - Coordinate[3].y)) <= 0) {
			return true;
		}
	}
	return false;
}
