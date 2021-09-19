/*==============================================================================

   �e�N�X�`���̕`�� [main.h]
                                                         Author : 
                                                         Date   : 
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once


#pragma warning(push)
#pragma warning(disable:4005)

#define _CRT_SECURE_NO_WARNINGS			// scanf ��warning�h�~
#include <stdio.h>

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <d3dx9.h>

#define DIRECTINPUT_VERSION 0x0800		// �x���Ώ�
#include "dinput.h"
#include "mmsystem.h"

#pragma warning(pop)

#include "Parameter.h"

//*****************************************************************************
// ���C�u�����̃����N
//*****************************************************************************
#pragma comment (lib, "d3d11.lib")		
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "d3dx11.lib")	
#pragma comment (lib, "d3dx9.lib")	
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "dxerr.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "dinput8.lib")


//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define SCREEN_SIZE 3/4

#define SCREEN_WIDTH	(1920)*SCREEN_SIZE				// �E�C���h�E�̕�
#define SCREEN_HEIGHT	(1080)*SCREEN_SIZE	        	// �E�C���h�E�̍���

#define SCREEN_WIDTH_CENTER (SCREEN_WIDTH / 2)
#define SCREEN_HEIGHT_CENTER (SCREEN_HEIGHT / 2)

#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define PI 3.14159265358979323846264338327950L
#define RADIAN PI/180.0

typedef unsigned int UINT;

enum {
	RESULT_WIN,
	RESULT_LOSE,
	RESULT_MAX
};

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
float frand();
