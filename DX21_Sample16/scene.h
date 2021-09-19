#pragma once

// �o�^�V�[���ꗗ
enum SCENE
{
	SCENE_NONE,		//�V�[�������Ȃ�
	SCENE_TITLE,	//�^�C�g��
	SCENE_GAME,		//�Q�[��
	SCENE_RESULT,	//���U���g

	SCENE_MAX		//�Ōゾ�Ƃ킩��z�������
};

void InitializeScene(SCENE index);
void TerminateScene(void);
void UpdateScene(void);
void DrawScene(void);

void SetScene(SCENE index);
void CheckScene(void);
