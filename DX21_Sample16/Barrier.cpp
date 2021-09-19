#include "Barrier.h"
#include "sprite.h"
#include "Texture.h"

void Barrier::Initialize()
{
	m_BarTexture = LoadTexture(TEX_NAME);
	for (int i = 0; i < BAR_NUM_MAX; i++) {
		bar_par[i].Position.x = 0.0f;
		bar_par[i].Position.y = 0.0f;
		bar_par[i].Frame = 0;
		bar_par[i].Size.x = 100.0f;
		bar_par[i].Size.y = 100.0f;
		bar_par[i].Use = false;
		bar_par[i].angle = 0.0f;
	}

	add_x = 0.0f;
}

void Barrier::Terminate()
{
}

void Barrier::Update()
{
	for (int i = 0; i < BAR_NUM_MAX; i++) {
		if (bar_par[i].Use) {
			if (bar_par[i].Frame >= 30) {
				bar_par[i].Use = false;

			}
			else {
				bar_par[i].Frame++;
				bar_par[i].Size.x += 20.0f;
				bar_par[i].Size.y += 20.0f;
			}
			bar_par[i].angle += add_angle;
		}
	}
}

void Barrier::Draw()
{
	for (int i = 0; i < BAR_NUM_MAX; i++) {
		if (bar_par[i].Use) {
			DrawSpriteColorRotate(m_BarTexture,
				bar_par[i].Position.x, bar_par[i].Position.y,
				bar_par[i].Size.x, bar_par[i].Size.y,
				1.0f, 1.0f, 1.0f, 1.0f, bar_par[i].angle,
				D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		}
	}
}

void Barrier::SetBarr(D3DXVECTOR2 pos)
{
	for (int i = 0; i < BAR_NUM_MAX; i++) {
		if (!bar_par[i].Use) {
			bar_par[i].Frame = 0;
			bar_par[i].Position = pos;
			bar_par[i].Size.x = 300.0f;
			bar_par[i].Size.y = 300.0f;
			bar_par[i].Use = true;
			break;
		}
	}
}

bool Barrier::PlayerDistance(int i, D3DXVECTOR2 plyaer_pos)
{
	return false;
}
