/*==============================================================================

   �V�[���Ǘ� [scene.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/

#include "scene.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "fade.h"


/*------------------------------------------------------------------------------
   �萔��`
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �\���̐錾
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �v���g�^�C�v�錾
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   �O���[�o���ϐ��̒�`
------------------------------------------------------------------------------*/
static SCENE g_SceneIndex = SCENE_NONE;
static SCENE g_SceneNextIndex = g_SceneIndex;

Title g_title;
Result g_result;
Game g_game;

/*------------------------------------------------------------------------------
   �������֐�
------------------------------------------------------------------------------*/
void InitializeScene(SCENE index)
{
	g_SceneIndex = g_SceneNextIndex = index;

	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		g_title.Init();
		break;

	case SCENE_GAME:
		g_game.Initialize();
		break;

	case SCENE_RESULT:
		g_result.Init();
		break;
	}
}

/*------------------------------------------------------------------------------
   �I������������֐�
------------------------------------------------------------------------------*/
void TerminateScene(void)
{
	switch (g_SceneIndex)
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		g_title.Uninit();
		break;

	case SCENE_GAME:
		g_game.Terminate();
		break;

	case SCENE_RESULT:
		g_result.result_num = g_game.result;
		g_result.stage_num = g_game.stage_num;
		g_result.Finalize();
		break;
	}
}

/*------------------------------------------------------------------------------
   �X�V����������֐�
------------------------------------------------------------------------------*/
void UpdateScene(void)
{
	switch( g_SceneIndex ) 
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		g_title.Update();
		break;

	case SCENE_GAME:
		g_game.Update();
		break;

	case SCENE_RESULT:
		g_result.Update();
		break;
	}

	UpdateFade();
}

/*------------------------------------------------------------------------------
   �`�揈��������֐�
------------------------------------------------------------------------------*/
void DrawScene(void)
{
	switch( g_SceneIndex )
	{
	case SCENE_NONE:
		break;

	case SCENE_TITLE:
		g_title.Draw();
		break;

	case SCENE_GAME:
		g_game.Draw();
		break;

	case SCENE_RESULT:
		g_result.Draw();
		break;
	}

	DrawFade();
}

/*------------------------------------------------------------------------------
   �V�[���J�ڂ�v������֐�
------------------------------------------------------------------------------*/
void SetScene(SCENE index)
{
	//�J�ڐ�V�[����ݒ肷��
	g_SceneNextIndex = index;
}

/*------------------------------------------------------------------------------
   �J�ڂ�v��������ꍇ�ɃV�[����؂�ւ���֐�
------------------------------------------------------------------------------*/
void CheckScene(void)
{
	//���݂̃V�[���ƑJ�ڐ�V�[��������Ă�����
	if( g_SceneIndex != g_SceneNextIndex )
	{
		//���݂̃V�[�����I��������
		TerminateScene();
		
		//�J�ڐ�V�[���̏������������s��
		InitializeScene(g_SceneNextIndex);
	}
}
