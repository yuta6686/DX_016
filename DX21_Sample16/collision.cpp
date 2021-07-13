//=============================================================================
//
// �����蔻�菈�� [collision.cpp]
// Author : 
//
//=============================================================================
#include "main.h"
#include "collision.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************


//*****************************************************************************
// �\���̒�`
//*****************************************************************************


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, D3DXVECTOR2 size1, D3DXVECTOR2 size2);
bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, float size1, float size2);


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************


//=============================================================================
// �����蔻�菈��
//=============================================================================
void UpdateCollision(void)
{
	PLAYER *player = GetPlayer();		// �v���C���[�̃|�C���^�[��������
	ENEMY  *enemy = GetEnemy();		// �G�l�~�[�̃|�C���^�[��������
	BULLET *bullet = GetBullet();		// �o���b�g�̃|�C���^�[��������

	// �G�Ƒ���L����(BB)
	if (player[0].use == true)
	{
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			if (enemy[i].use == false)
				continue;

//			if (CollisionBB(player->pos, enemy[i].pos, D3DXVECTOR2(player->w, player->h), D3DXVECTOR2(enemy[i].w, enemy[i].h)))
			if (CollisionBC(player->pos, enemy[i].pos, player->h/2, enemy[i].h/2))
			{
				// ����L�����N�^�[�͎���

				// �G�L�����N�^�[�͓|�����
				enemy[i].use = false;

				// HP��������

			}
		}
	}

	// �e�ƓG(BB)
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (bullet[i].use == false)
			continue;

		for (int j = 0; j < ENEMY_MAX; j++)
		{
			if (enemy[j].use == false)
				continue;
				
			if (CollisionBB(bullet[i].pos, enemy[j].pos, D3DXVECTOR2(bullet[i].w, bullet[i].h), D3DXVECTOR2(enemy[j].w, enemy[j].h)))
			{
				bullet[i].use = false;		// �e�̏��ŏ������s��
				enemy[j].use = false;		// �G�͓|�����

				// �X�R�A�v�Z

				//break;					// �P�񓖂����ďI���̎��͂�����break����B�P�t���[�����̊ԗL���Ȃ�break���R�����g�ɂ���B
			}
		}
	}

	// �{�X�ƒe(BC)

	// �����ƓG�̒e(BC)

	// ���S�������ԑJ��

}

//=============================================================================
// BB�ɂ�铖���蔻�菈��
// ��]�͍l�����Ȃ�
// �߂�l�F�������Ă���true
//=============================================================================
bool CollisionBB(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, D3DXVECTOR2 size1, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, max1;
	D3DXVECTOR2 min2, max2;

	min1.x = pos1.x - size1.x / 2;
	min1.y = pos1.y - size1.y / 2;
	max1.x = pos1.x + size1.x / 2;
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x - size2.x / 2;
	min2.y = pos2.y - size2.y / 2;
	max2.x = pos2.x + size2.x / 2;
	max2.y = pos2.y + size2.y / 2;

	//X���̔���
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Y���̔���
		if (min1.y < max2.y && max1.y > min2.y)
		{
			//�S�Ă̏�����TRUE�Ȃ�q�b�g����
			return true;
		}
	}

	return false;
}

//=============================================================================
// BC�ɂ�铖���蔻�菈��
// �T�C�Y�͔��a
// �߂�l�F�������Ă���true
//=============================================================================
bool CollisionBC(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2, float size1, float size2)
{
	//pos1��pos2���Ȃ��x�N�g�������
	D3DXVECTOR2 vDistance = pos1 - pos2;

	//vDistance�̃x�N�g�����𓾂�
	float length;
//	length = D3DXVec2Length(&vDistance);
	length = D3DXVec2LengthSq(&vDistance);

//	float size = size1 + size2;
	float size = (size1 + size2) * (size1 + size2);

	//1��2�̔��a�𑫂��Ĕ��肷��
	//�����̃x�N�g�����̕������������
	//�q�b�g���Ă���
	if (length < size)
	{
		return true;
	}

	return false;
}
