#include "Obstacle.h"
#include "sprite.h"

void Obstacle::Init()
{
	SetObsTexture();
	for (int i = 0; i < OBS_NUM_MAX; i++) {
		obs_par[i].opm.Position.x = 0.0f;
		obs_par[i].opm.Position.y = 0.0f;
		obs_par[i].use = false;
		obs_par[i].opm.Size.x = 100.0f;
		obs_par[i].opm.Size.y = 100.0f;
	}

	for (int i = 0; i < InitNum_; i++) {
		obs_par[i].opm = InitPosition[i];
		obs_par[i].use = true;

		//obs_par[i].opm.Size.x *= SCREEN_SIZE;
		//obs_par[i].opm.Size.y *= SCREEN_SIZE;

		obs_par[i].opm.Position.x += SCREEN_WIDTH_CENTER;
		obs_par[i].opm.Position.y += SCREEN_HEIGHT_CENTER;
	}

	

	HitStop_ = 0.0f;
}

void Obstacle::Uninit()
{
}

void Obstacle::Update()
{
	for (int i = 0; i < OBS_NUM_MAX; i++) {
		obs_par[i].opm.Position.x -= OBS_SPEED * HitStop_;
		if (obs_par[i].use) {

			if (obs_par[i].opm.Position.x < -SCREEN_WIDTH)
				obs_par[i].use = false;

			if (obs_par[i].opm.Position.y < -SCREEN_HEIGHT / 2)
				obs_par[i].use = false;

			if (obs_par[i].opm.Position.y < -SCREEN_HEIGHT / 2)
				obs_par[i].use = false;
		}
	}
}

void Obstacle::Draw()
{
	for (int i = 0; i < OBS_NUM_MAX; i++) {

		if (obs_par[i].use) {

			DrawSpriteColor(GetObsTexture(), obs_par[i].opm.Position.x, obs_par[i].opm.Position.y,
				obs_par[i].opm.Size.x, obs_par[i].opm.Size.y,
				0.0f, 0.0f, 1.0f, 1.0f, D3DXCOLOR(HitStop_, HitStop_, HitStop_, 1.0f));
		}
	}
}

void Obstacle::SetObs(D3DXVECTOR2 pos)
{
	for (int i = 0; i < OBS_NUM_MAX; i++) {
		if (obs_par[i].use == false) {
			obs_par[i].opm.Position.x = pos.x;
			obs_par[i].opm.Position.y = pos.y;
			obs_par[i].use = true;
			break;
		}
	}
}

void Obstacle::SetObs(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	for (int i = 0; i < OBS_NUM_MAX; i++) {
		if (obs_par[i].use == false) {
			obs_par[i].opm.Position.x = pos.x;
			obs_par[i].opm.Position.y = pos.y;
			obs_par[i].opm.Size.x = size.x;
			obs_par[i].opm.Size.y = size.y;
			obs_par[i].use = true;
			break;
		}
	}
}

int Obstacle::ObsPlayerCollition(D3DXVECTOR2 pos, D3DXVECTOR2 size)
{
	for (int i = 0; i < OBS_NUM_MAX; i++) {
		if (obs_par[i].use) {
			if (obs_par[i].opm.Position.x + (obs_par[i].opm.Size.x / 2.0f) >= pos.x - size.x / 2.0f &&
				obs_par[i].opm.Position.x - (obs_par[i].opm.Size.x / 2.0f) <= pos.x + size.x / 2.0f &&
				obs_par[i].opm.Position.y + obs_par[i].opm.Size.y / 2.0f >= pos.y - size.y / 2.0f &&
				obs_par[i].opm.Position.y - obs_par[i].opm.Size.y / 2.0f <= pos.y + size.y / 2.0f) {
				return i;
			}
		}
	}
	return -1;
}
