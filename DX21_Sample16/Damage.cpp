#include "Damage.h"
#include "sprite.h"
#include "texture.h"

void Damage::Init()
{
	DTex[0] = LoadTexture(TEX_NAME_000);
	DTex[1] = LoadTexture(TEX_NAME_001);
	DTex[2] = LoadTexture(TEX_NAME_002);
	DTex[3] = LoadTexture(TEX_NAME_003);

	r_ = 0.0f;
	g_ = 0.0f;
	b_ = 0.0f;
	a_ = 0.0f;

	wave = 0.0f;

	d_state = DAMAGE_NONE;
	d_next = DAMAGE_NONE;

	select_tex_num = 0;
}
void Damage::Uninit()
{
}
void Damage::Update()
{
	if (d_state == DAMAGE_TAKE) {
		if (wave >= 360.0f) {
			wave = 0.0f;
			d_state = DAMAGE_NONE;
		}
		wave += 5.0f;
		r_ = sinf(wave * RADIAN);
		a_ = sinf(wave * RADIAN);
	}

}
void Damage::Draw()
{
	if (d_state == DAMAGE_NONE)return;
	DrawSpriteColor(DTex[select_tex_num],SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f, 1.0f, 1.0f,
		D3DXCOLOR(r_, g_, b_, a_));
}

void Damage::TakeDamage()
{
	d_state = DAMAGE_TAKE;
}
