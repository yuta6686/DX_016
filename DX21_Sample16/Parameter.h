//=============================================================================
//
// パラメーター [title.h]
// Author : 
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************




//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
class PSParameter {
public:
	D3DXVECTOR2 Position;
	D3DXVECTOR2 Size;
};

class Parameter {
public:
	D3DXVECTOR2 Position;
	D3DXVECTOR2 Size;
	bool Use;
};

class ParameterFrame : public Parameter {
public:
	int Frame;
};

class ParameterAlpha :public Parameter {
public:
	float alpha;
};

class ParameterAlphaFrame :public ParameterFrame {
public:
	float alpha;
};

class MovePrm {
public:
	D3DXVECTOR2 Position;
	D3DXVECTOR2 Size;

	//加速度
	float acceleration;

	//x方向への継続的な移動
	float x_move;

	//弾が出る間隔
	int bullet_interval;

	//エネミーのパターン
	int pat = 0;
};

class JSG {
public:
	D3DXVECTOR2 pos_;
	float size_;
	float blink_;	//点滅
	float angle_;
	float acceleration_;	//加速度
	bool use_;
	int count_;
	int frame;
};

class Bar :public ParameterFrame {
public:
	float angle;
};

class BulN {
public:
	D3DXVECTOR2 pos;
	D3DXVECTOR2 vel;
	float size;
	bool use;

};

struct ObsPrm {
	D3DXVECTOR2 Position;
	D3DXVECTOR2 Size;
};

class Obs {
public:
	ObsPrm opm;
	D3DXVECTOR2 vel;
	bool use;
};