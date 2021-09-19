//=============================================================================
//
// �p�����[�^�[ [title.h]
// Author : 
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************




//*****************************************************************************
// �v���g�^�C�v�錾
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

	//�����x
	float acceleration;

	//x�����ւ̌p���I�Ȉړ�
	float x_move;

	//�e���o��Ԋu
	int bullet_interval;

	//�G�l�~�[�̃p�^�[��
	int pat = 0;
};

class JSG {
public:
	D3DXVECTOR2 pos_;
	float size_;
	float blink_;	//�_��
	float angle_;
	float acceleration_;	//�����x
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