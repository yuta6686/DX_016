#include "Just_Guard.h"
#include "texture.h"
#include "sprite.h"

void Just_Guard::Initialize(void)
{
	JustGuardTexture = LoadTexture(TEX_NAME);
	jsg.pos_.x = 0.0f;
	jsg.pos_.y = 0.0f;
	jsg.size_ = 400.0f;
	jsg.blink_ = 0.0f;
	jsg.angle_ = 0.0f;
	jsg.acceleration_ = 1.0f;
	jsg.use_ = false;
	jsg.count_ = 0;
	jsg.frame = 0;

	JSR_Texture = LoadTexture(JSR_TEX_NAME);
	jsgr.pos_.x = 0.0f;
	jsgr.pos_.y = 0.0f;
	jsgr.size_ = 600.0f;
	jsgr.blink_ = 0.0f;
	jsgr.angle_ = 0.0f;
	jsgr.acceleration_ = 1.0f;
	jsgr.use_ = false;
	jsgr.count_ = 0;
	jsgr.frame = 0;

	JSE_Texture = LoadTexture(JSE_TEX_NAME);
	jsge.pos_.x = 0.0f;
	jsge.pos_.y = 0.0f;

	jsge.blink_ = 0.0f;
	jsge.angle_ = 0.0f;
	jsge.acceleration_ = 1.0f;
	jsge.use_ = false;
	jsge.count_ = 0;
	jsge.frame = 0;

	uv_ = 0.0f;
}

void Just_Guard::Terminate(void)
{
}

void Just_Guard::Update(void)
{
	if (jsg.count_ >= 180) {
		jsg.use_ = false;
		jsg.count_ = 0;
	}
	else jsg.count_++;

	if (jsg.use_) {
		if (jsg.angle_ >= 180.0f) {
			jsg.angle_ = 0.0f;
		}
		else {
			jsg.acceleration_ += ACCELERATION;
			jsg.angle_ += jsg.acceleration_;

			if (jsg.angle_ <= 30.0f && jsg.angle_ >= 0.0f ||
				jsg.angle_ >= 150.0f && jsg.angle_ <= 180.0f) {
				jsg.blink_ = 0.0f;
			}
			else {
				jsg.blink_ = sinf(fabs(jsg.angle_) * RADIAN);
			}
		}
	}

	if (jsgr.count_ >= 180) {
		jsgr.use_ = false;
		jsgr.count_ = 0;
	}
	else jsgr.count_++;

	if (jsgr.use_) {
		if (jsgr.frame > 15) {
			jsgr.frame = 0;
			jsgr.use_ = false;
		}
		else {
			jsgr.frame++;
		}

		if (jsgr.angle_ >= 180.0f) {
			jsgr.angle_ = 0.0f;
		}
		else {

			jsgr.angle_ += 10.0f;

			if (jsgr.angle_ <= 30.0f && jsg.angle_ >= 0.0f ||
				jsgr.angle_ >= 150.0f && jsg.angle_ <= 180.0f) {
				jsgr.blink_ = 0.0f;
			}
			else {
				jsgr.blink_ = sinf(fabs(jsg.angle_) * RADIAN);
			}
		}
	}

	if (jsge.use_) {
		if (jsge.frame > 180) {
			jsge.frame = 0;
			jsge.use_ = false;
		}
		else {
			jsge.frame++;
		}

		if (jsge.angle_ >= 180.0f) {
			jsge.angle_ = 0.0f;
		}
		else {
			jsge.angle_ += 10.0f;
		}

		jsge.blink_ = sinf(jsge.angle_ * RADIAN);

		uv_ += 0.01f;
	}
}

void Just_Guard::Draw(void)
{
	if (jsg.use_) {
		DrawSpriteColor(JustGuardTexture,
			jsg.pos_.x, jsg.pos_.y,
			jsg.size_ * jsg.blink_ + 100.0f, jsg.size_ * jsg.blink_ + 100.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, jsg.blink_));
	}

	if (jsgr.use_) {
		DrawSpriteColor(JSR_Texture,
			jsgr.pos_.x , jsgr.pos_.y,
			jsgr.size_ * sinf(jsgr.angle_ * RADIAN), jsgr.size_ * sinf(jsgr.angle_ * RADIAN),
			jsgr.frame % JSR_X_NUM * JSR_WIDTH,
			jsgr.frame / JSR_Y_NUM * JSR_HEIGHT,
			JSR_WIDTH, JSR_HEIGHT,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, sinf(RADIAN * jsgr.angle_)));
	}

	if (jsge.use_) {
		DrawSpriteColor(JSE_Texture,
			jsge.pos_.x + SCREEN_WIDTH_CENTER, jsge.pos_.y+ SCREEN_HEIGHT_CENTER,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			uv_, 0.0f, 0.25f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, jsge.blink_));
	}
}

void Just_Guard::Set(D3DXVECTOR2 Pos)
{
	if (jsg.use_ == false) {
		jsg.pos_ = Pos;
		jsg.angle_ = 0.0f;
		jsg.count_ = 0;
		jsg.acceleration_ = 1.0f;
		jsg.blink_ = 0;
		jsg.use_ = true;
	}

	if (jsgr.use_ == false) {
		jsgr.pos_ = Pos;
		jsgr.angle_ = 0.0f;
		jsgr.count_ = 0;
		jsgr.acceleration_ = 1.0f;
		jsgr.blink_ = 0;
		jsgr.use_ = true;
	}
	if (jsge.use_ == false) {
		jsge.angle_ = 0.0f;
		jsge.count_ = 0;
		jsge.acceleration_ = 1.0f;
		jsge.blink_ = 0;
		jsge.use_ = true;

		uv_ = 0.25f;
	}
}
