/*==============================================================================

   シーン管理 [scene.cpp]
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
   定数定義
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   構造体宣言
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   プロトタイプ宣言
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
   グローバル変数の定義
------------------------------------------------------------------------------*/
static SCENE g_SceneIndex = SCENE_NONE;
static SCENE g_SceneNextIndex = g_SceneIndex;

Title g_title;
Result g_result;
Game g_game;

/*------------------------------------------------------------------------------
   初期化関数
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
   終了処理をする関数
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
   更新処理をする関数
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
   描画処理をする関数
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
   シーン遷移を要求する関数
------------------------------------------------------------------------------*/
void SetScene(SCENE index)
{
	//遷移先シーンを設定する
	g_SceneNextIndex = index;
}

/*------------------------------------------------------------------------------
   遷移を要求がある場合にシーンを切り替える関数
------------------------------------------------------------------------------*/
void CheckScene(void)
{
	//現在のシーンと遷移先シーンが違っていたら
	if( g_SceneIndex != g_SceneNextIndex )
	{
		//現在のシーンを終了させる
		TerminateScene();
		
		//遷移先シーンの初期化処理を行う
		InitializeScene(g_SceneNextIndex);
	}
}
