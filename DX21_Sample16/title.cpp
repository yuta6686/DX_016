//=============================================================================
//
// タイトル画面処理 [title.cpp]
// Author : 
//
//=============================================================================
#include "title.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "sound.h"
#include <math.h>

//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
static int	g_TextureNo = 0;	// テクスチャ情報
static int	g_BGMNo = 0;		// BGM識別子

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT Title::Init(void)
{
	bar_.Initialize();

	//Texture
	{
		ApaceMonsterTexture = LoadTexture(AM_TEX_NAME);
		SpaceTexture = LoadTexture(SPACE_TEX_NAME);
		TitleTexture = LoadTexture(TITLE_TEX_NAME);

		rep(i, SPHERE_NUM)
			SpherTexture[i] = LoadTexture(SPHERE_TEX_NAME[i]);
	}

	//Sound
	{
		g_BGMNo = LoadSound("data/BGM/sample000.wav");
		//Playsound(BGMの番号,0～254);
		PlaySound(g_BGMNo, 254);
	}
	
	//_title-init
	{
		_title.Position = D3DXVECTOR2(SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER);
		_title.Size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
		_title.Frame = 0;
		_title.Use = false;
		_title.Size_Max = false;
	}

	//_sph-init
	rep(i, SPHERE_NUM) {
		rep(j, SPHERE_NUM_MAX) {
			_sph[i][j].Position = D3DXVECTOR2(rand() % SCREEN_WIDTH, SCREEN_HEIGHT);
			_sph[i][j].Size = D3DXVECTOR2(100.0f, 100.0f);
			_sph[i][j].Use = false;
			_sph[i][j].barrier_use = false;
			_sph[i][j].pat = i;
			_sph[i][j].alpha = 1.0f;
		}
	}
	

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void Title::Uninit(void)
{
	bar_.Terminate();
	StopSoundAll();
}

//=============================================================================
// 更新処理
//=============================================================================
void Title::Update(void)
{
	

	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_GAME);
	}

	if (!_title.Use)
		SetTitle(SCREEN_WIDTH_CENTER/2 + TITILE_MAX_SIZE/4, SCREEN_HEIGHT_CENTER/2);

	if (_title.Use) {
		if (title_counter <= COUNTER_MAX) {
			title_counter++;
		}
		else {

			title_counter = 0;
			_title.Frame++;
		}
		if (_title.Frame >= (TITLE_X_NUM * TITLE_X_NUM)) {
			_title.Use = false;
		}
	}
		

	if (sphere_counter >= SPHERE_NUM) {
		sphere_counter = 0;
	}
	else {
		SetSph(sphere_counter,rand()%SCREEN_WIDTH, SCREEN_HEIGHT ,(rand()% 100 ) + 50.0f);
		sphere_counter++;
	}

	if (title_dig_rad >= 360.0f) {
		title_dig_rad = 0.0f;
	}
	else {
		title_dig_rad += DEGREE;
		if (title_dig_rad >= -20.0f)_title.Size_Max = true;
	}

	_title.Size.x = TITILE_MAX_SIZE * fabs(sinf(title_dig_rad * RADIAN));
	_title.Size.y = TITILE_MAX_SIZE * fabs(sinf(title_dig_rad * RADIAN));

	if (_title.Size_Max) {
		if (rotate_title_dig_rad >= 360.0f) {
			rotate_title_dig_rad = 0.0f;
		}
		else {
			rotate_title_dig_rad += 10.0f * DEGREE;
		}
		_title.Size.x = _title.Size.x * fabs(cosf(rotate_title_dig_rad * RADIAN));
	}

	for (int i = 0; i < SPHERE_NUM; i++) {
		for (int j = 0; j < SPHERE_NUM_MAX; j++) {
			if (_sph[i][j].Size.x >= 0 && _sph[i][j].Size.y >= 0) {
				_sph[i][j].Size.x -= 1.0f;
				_sph[i][j].Size.y -= 1.0f;
			}
			else {
				_sph[i][j].Size.x = _sph[i][j].Size.y = 0.0f;
				_sph[i][j].Use = false;
			}

			if (!_sph[i][j].Use)
				break;

			if (sphere_dig_rad >= 360.0f) {
				sphere_dig_rad = 0.0f;
			}
			else {
				sphere_dig_rad += DEGREE / 10.0f;
			}

			_sph[i][j].alpha = fabs((sin(sphere_dig_rad * RADIAN)));

			if (_sph[i][j].Position.y <= -SCREEN_HEIGHT / 2.0f) {
				_sph[i][j].Position.y = 0.0f;
				_sph[i][j].Use = false;
			}
			else {
				_sph[i][j].Position.y -= 10.0f;
			}

			if (_sph[i][j].Position.y + _sph[i][j].Size.y / 2.0f <= _title.Position.y + _title.Size.y / 2.0f &&
				_sph[i][j].Position.y - _sph[i][j].Size.y / 2.0f >= _title.Position.y - _title.Size.y / 2.0f &&
				_sph[i][j].Position.x + _sph[i][j].Size.x / 2.0f <= _title.Position.x + _title.Size.x / 2.0f &&
				_sph[i][j].Position.x - _sph[i][j].Size.x / 2.0f >= _title.Position.x - _title.Size.x / 2.0f) {
				_sph[i][j].alpha = 0.0f;
				if (!_sph[i][j].barrier_use) {
					bar_.SetBarr(_sph[i][j].Position);
					_sph[i][j].barrier_use = true;
				}
				else {
					/*for (int i = 0; i < bar_.GetBarNumMax(); i++) {
						if (bar_.GetBarr()[i].Frame >= 15) {
							bar_.GetBarr()[i].Use = false;
						}
					}*/



				}

			}
			
		}
	}
	bar_.Update();
}

void Title::SetSph(int pat, float x, float y, float size)
{
	for (int i = 0; i < SPHERE_NUM_MAX; i++) {
		if (_sph[pat][i].Use == false) {
			_sph[pat][i].pat = pat;
			_sph[pat][i].Position.x = x;
			_sph[pat][i].Position.y = y;
			_sph[pat][i].Size.x = _sph[pat][i].Size.y = size;
			_sph[pat][i].Use = true;
			_sph[pat][i].alpha = 0.0f;
			_sph[pat][i].barrier_use = false;
			break;
		}
	}
}

void Title::SetTitle(float x, float y) {
	if (_title.Use == false) {
		_title.Position.x = x;
		_title.Position.y = y;
		_title.Frame = 0;
		//g_title.Size = MakeFloat2(1080.0f, 1080.0f);
		_title.Use = true;
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void Title::Draw(void)
{
	
	// １枚のポリゴンの頂点とテクスチャ座標を設定
	
	//Space
	{
		DrawSpriteColor(SpaceTexture, SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER,
			SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f,1.0f,1.0f,1.0f));
	}

	//ApaceMonster
	{
		DrawSpriteColor(ApaceMonsterTexture, SCREEN_WIDTH_CENTER, SCREEN_HEIGHT_CENTER,
			SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f,
			D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	}
	//Title
	{
		DrawSprite(TitleTexture, _title.Position.x+200.0f, _title.Position.y+200.0f,
			_title.Size.x, _title.Size.y, 
			(_title.Frame % TITLE_X_NUM)* TITLE_WIDTH,
			(_title.Frame / TITLE_Y_NUM) * TITLE_HEIGHT,
			TITLE_WIDTH, TITLE_HEIGHT);
	}
	 
	//Sphere
	{
		rep(i, SPHERE_NUM) {
			rep(j, SPHERE_NUM_MAX) {
				if (!_sph[i][j].Use)break;
				DrawSpriteColor(SpherTexture[i],
					_sph[i][j].Position.x, _sph[i][j].Position.y,
					_sph[i][j].Size.x, _sph[i][j].Size.y, 0.0f, 0.0f, 1.0f, 1.0f,
					D3DXCOLOR(1.0f, 1.0f, 1.0f, _sph[i][j].alpha));
			}
		}
	}
	bar_.Draw();
}

