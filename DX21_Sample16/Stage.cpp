#include "Stage.h"
#include "input.h"
#include "fade.h"

MovePrm EnemyInitPosition[] = {

	//1ステージ目の情報
  //(Float2 pos,Float2 size,float acceleration,float x_move,int bullet_interval, int pattern)
	//xは500.0fまで。
	{D3DXVECTOR2(1200.0f,100.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,120,1},
	{D3DXVECTOR2(1400.0f,-100.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,120,1},
	{D3DXVECTOR2(3000.0f,-300.0f),D3DXVECTOR2(350,200.0f),0.0f,2.0f,120,1},
	{D3DXVECTOR2(3000.0f, 300.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,120,0},
	{D3DXVECTOR2(4400,200.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,120,2},
	{D3DXVECTOR2(4600.0f,-300.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,120,2},
	{D3DXVECTOR2(4800.0f,200.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,120,2},
};
int EnemyInitFirstNum = sizeof(EnemyInitPosition) / sizeof(EnemyInitPosition[0]);

MovePrm EnemyInitPosition_Second[] = {
	//2ステージ目
	{D3DXVECTOR2(1000.0f,-100.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,60,0},
	{D3DXVECTOR2(2600.0f, 200.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,60,0},
	{D3DXVECTOR2(6000.0f,   0.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,60,0},
	{D3DXVECTOR2(7000.0f,-300.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,60,0},
	{D3DXVECTOR2(7000.0f,300.0f),D3DXVECTOR2(400,200.0f),0.0f,2.0f,60,0},

};
int EnemyInitSecondNum = sizeof(EnemyInitPosition_Second) / sizeof(EnemyInitPosition_Second[0]);

MovePrm EnemyInitPosition_Third[] = {
	//3ステージ目
	{D3DXVECTOR2(200.0f,100.0f),D3DXVECTOR2(400,200.0f),5.5f,1.0f,60,1},
	{D3DXVECTOR2(300.0f,100.0f),D3DXVECTOR2(400,200.0f),5.5f,1.0f,60,1},
	{D3DXVECTOR2(700.0f,100.0f),D3DXVECTOR2(400,200.0f),1.5f,1.0f,60,0},
};
int EnemyInitThirdNum = sizeof(EnemyInitPosition_Third) / sizeof(EnemyInitPosition_Third[0]);

ObsPrm ObsInitPos[] = {
	{D3DXVECTOR2 (-800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(0.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2 (200.0f,200.0f)},
	{D3DXVECTOR2(1000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(1200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(1600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(2000.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2200.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(2400.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2600.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(2800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(3200.0f,-SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3200.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3200.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3200.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3200.0f,400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3200.0f,600.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(3400.0f,-SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,600.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(3400.0f,-SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,600.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(3800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

};
int ObsInitFirstNum = sizeof(ObsInitPos) / sizeof(ObsInitPos[0]);

ObsPrm ObsInitPos_Second[] = {
	{D3DXVECTOR2(-800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(0.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(1000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(1800.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2000.0f,200.0f),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(2600.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2800.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(3400.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3600.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(3800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(4000.0f,0.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4200.0f,0.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(4400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(5400.0f,0.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5400.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5400.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5400.0f,-500.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(5600.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5600.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5600.0f,-500.0f),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(5800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5800.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5800.0f,-500.0f),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(6000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6000.0f,SCREEN_HEIGHT_HARF - 200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6000.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6000.0f,-500.0f),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(6200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6200.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6200.0f,-500.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(6400.0f,0.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6400.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6400.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6400.0f,-500.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(6600.0f,0.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6600.0f,-200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6600.0f,-400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6600.0f,-500.0f),D3DXVECTOR2(200.0f,200.0f)},
};
int ObsInitSecondNum = sizeof(ObsInitPos_Second) / sizeof(ObsInitPos_Second[0]);

ObsPrm ObsInitPos_Third[] = {
	{D3DXVECTOR2(-800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(-200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},



	{D3DXVECTOR2(400.0f,SCREEN_HEIGHT_HARF - 300.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(400.0f,SCREEN_HEIGHT_HARF - 500.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(400.0f,SCREEN_HEIGHT_HARF - 700.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(400.0f,SCREEN_HEIGHT_HARF - 900.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(400.0f,SCREEN_HEIGHT_HARF - 1000.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(600.0f,SCREEN_HEIGHT_HARF - 1000.0f),D3DXVECTOR2(200.0f,200.0f)},


	{D3DXVECTOR2(800.0f,SCREEN_HEIGHT_HARF - 300.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(800.0f,SCREEN_HEIGHT_HARF - 500.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(800.0f,SCREEN_HEIGHT_HARF - 700.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(800.0f,SCREEN_HEIGHT_HARF - 900.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(800.0f,SCREEN_HEIGHT_HARF - 1000.0f),D3DXVECTOR2(200.0f,200.0f)},



	{D3DXVECTOR2(1200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1400.0f,SCREEN_HEIGHT_HARF - 200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1400.0f,SCREEN_HEIGHT_HARF - 400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1400.0f,SCREEN_HEIGHT_HARF - 600.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1400.0f,SCREEN_HEIGHT_HARF - 800.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(1600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1600.0f,SCREEN_HEIGHT_HARF - 200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1600.0f,SCREEN_HEIGHT_HARF - 400.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1600.0f,SCREEN_HEIGHT_HARF - 600.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(1600.0f,SCREEN_HEIGHT_HARF - 800.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(2200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2200.0f,SCREEN_HEIGHT_HARF - 200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2200.0f,SCREEN_HEIGHT_HARF - 800.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2200.0f,SCREEN_HEIGHT_HARF - 1000.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(2400.0f,SCREEN_HEIGHT_HARF - 1000.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2600.0f,SCREEN_HEIGHT_HARF - 1000.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(2800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2800.0f,SCREEN_HEIGHT_HARF - 200.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2800.0f,SCREEN_HEIGHT_HARF - 800.0f),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(2800.0f,SCREEN_HEIGHT_HARF - 1000.0f),D3DXVECTOR2(200.0f,200.0f)},

	{D3DXVECTOR2(3000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(3800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(4800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5200.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5400.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5600.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(5800.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
	{D3DXVECTOR2(6000.0f,SCREEN_HEIGHT_HARF),D3DXVECTOR2(200.0f,200.0f)},
};
int ObsInitThirdNum = sizeof(ObsInitPos_Third) / sizeof(ObsInitPos_Third[0]);

float goal_pos_x[STAGE_NUM_MAX] =
{
	2500.0f,
	3200.0f,
	2000.0f
};

HRESULT Stage::Init()
{
	SetInit();

	player_.Init();
	enemy_.Init();
	bg_.Initialize();
	goal_.Initialize();
	dmg.Init();
	obs.Init();

	return S_OK;
}




void Stage::Uninit()
{
	player_.Uninit();
	enemy_.Uninit();
	bg_.Terminate();
	goal_.Terminate();
	dmg.Uninit();
	obs.Uninit();
}

void Stage::Update()
{
	HitStop();

	GoalSet();

	EnemySetBullet();

	PlayerEnemyCollUpdate();

	ShotBeam();
	//ShotBeam_boss();

	obs.Update();
	player_.Update();
	enemy_.Update();
	bg_.Update();
	goal_.Update();
	dmg.Update();
}

void Stage::Draw()
{
	
	bg_.Draw();
	obs.Draw();
	enemy_.Draw();
	player_.Draw();
	goal_.Draw();
	dmg.Draw();

}

void Stage::SetInit()
{
	enemy_.SetStageNum(stage_num_);

	bg_.SetStageNum(stage_num_);

	switch (stage_num_)
	{
	case 0:
		enemy_.SetInitPos(&EnemyInitPosition[0]);
		enemy_.SetInitNum(EnemyInitFirstNum);
		enemy_loop = EnemyInitFirstNum;

		obs.SetInitPos(&ObsInitPos[0]);
		obs.SetInitNum(ObsInitFirstNum);
		break;
	case 1:
		enemy_.SetInitPos(&EnemyInitPosition_Second[0]);
		enemy_.SetInitNum(EnemyInitSecondNum);
		enemy_loop = EnemyInitSecondNum;

		obs.SetInitPos(&ObsInitPos_Second[0]);
		obs.SetInitNum(ObsInitSecondNum);
		break;

	case 2:
		enemy_.SetInitPos(&EnemyInitPosition_Third[0]);
		enemy_.SetInitNum(EnemyInitThirdNum);
		enemy_loop = EnemyInitThirdNum;

		obs.SetInitPos(&ObsInitPos_Third[0]);
		obs.SetInitNum(ObsInitThirdNum);
		break;
	default:
		enemy_.SetInitPos(&EnemyInitPosition[0]);
		enemy_.SetInitNum(EnemyInitFirstNum);
		enemy_loop = EnemyInitFirstNum;

		obs.SetInitPos(&ObsInitPos[0]);
		obs.SetInitNum(ObsInitFirstNum);
		break;
	}

	result = RESULT_WIN;
}


void Stage::HitStop()
{
	if (invincible) {
		hitStop = 0.3f;
	}
	else {
		hitStop = 1.0f;
	}
	player_.SetHitStop(hitStop);
	enemy_.SetHitStop(hitStop);
	obs.SetHitStop(hitStop);
	//boss.SetHitStop(hitStop);
	bg_.SetHitStop(hitStop);
	enemy_.bln.SetHitStop(hitStop);
	//boss.bln.SetHitStop(hitStop);
}

void Stage::GoalSet()
{
	GoalUpdate();

	switch (stage_num_)
	{
	case 0:
		if (bg_.GetBGPos().x < BG_INIT_POS_X - goal_pos_x[0]) {
			goal_.SetItem(D3DXVECTOR2(800.0f, SCREEN_HEIGHT_CENTER), D3DXVECTOR2(300.0f, 300.0f));
			bg_.SetStop(true);
		}
		break;
	case 1:
		if (bg_.GetBGPos().x < BG_INIT_POS_X - goal_pos_x[1]) {
			goal_.SetItem(D3DXVECTOR2(800.0f, SCREEN_HEIGHT_CENTER), D3DXVECTOR2(300.0f, 300.0f));
			bg_.SetStop(true);
		}
		break;
	case 2:
		if (bg_.GetBGPos().x < BG_INIT_POS_X - goal_pos_x[2] && !boss_appear) {
			bg_.SetStop(true);
			boss_appear = true;
		}
		break;
	default:
		break;
	}

	player_.SetObs(&obs);

	player_.coll = obs.ObsPlayerCollition(player_.GetPlayerPos(), player_.GetPlayerSize());
}

void Stage::GoalUpdate()
{
	if (goal_.GetGoalUse()) {
		if (goal_.Collition(player_.GetPlayerPos(), player_.GetPlayerSize())) {
			//ゴール後の処理　次のステージへ
			stage_num_flag = true;
			result = RESULT_WIN;
			SceneTransition(SCENE_RESULT);

		}
	}
}

//----------PlayerEnemyCollUpdate-------------------------------
void Stage::PlayerEnemyCollUpdate()
{
	enemy_coll_num = DudgeCollisionEnemy();
	bullet_coll_num = DudgeCollisionBullet();
	
	//プレイヤーのジャスガ位置調整
	

	PlayerInv();

	//プレイヤーのビームのポジションをフレーム毎にセット
	player_.beam.SetPos(player_.GetPlayerPos());

	//エネミーとビームの当たり判定
	EnemyCollBeam();

	if (invincible) {

		InvincibleCount();

		//あたってなかったら帰る
		if (enemy_coll_num < 0 && bullet_coll_num < 0)
			return;

		//エネミーとプレイヤーが衝突しているか
		if (enemy_coll_num >= 0) 
			InvincibleUpdate_Enemy();
		

		if (enemy_coll_num >= 0) 
			InvincibleUpdate_EnemyBullet();
		

	}
	else {

		//あたってなかったら帰る
		if (enemy_coll_num < 0 && bullet_coll_num < 0)
			return;

		//ジャストガードのフレーム
		JustCounterUpdate();

		if (player_.just) {
			//ボタンが押されたら
			if(GetKeyboardTrigger(DIK_LEFT)){
				//ジャスガチュートリアルの非表示処理
				//ptb.PressYButton();

				JustUpdate_Enemy();

				JustUpdate_EnemyBullet();
			}

			
			/*for (int i = 0; i < player_.bar.GetBarNumMax(); i++) {
				if (player_.bar.GetBarr()[i].Use) {
					player_.bar.SetBrrPos(i, player_.player_par.Position);
				}
			}*/
		}
		else {
			if (player_.death) {
				
				
				DeathUpdate_Enemy();

				DeathUpdate_EnemyBullet();
				
				
			}
		}
	}
}

void Stage::InvincibleUpdate_Enemy()
{
	//エネミー崩壊エフェクト
	for (int i = 0; i < 3; i++) {
		if (!enemy_.enemy_par[i][enemy_coll_num].use)continue;
		enemy_.eep_.Set(enemy_.enemy_par[i][enemy_coll_num].emp.Position);
		//exp.SetExplosion(enemy_.GetEnemyPos(enemy_coll_num).x, enemy_.GetEnemyPos(enemy_coll_num).y);

	}

	//衝突エネミーの消去
	enemy_.SetUse(enemy_coll_num, false);
}

void Stage::JustUpdate_Enemy()
{
	for (int i = 0; i < 3; i++) {
		if (!enemy_.enemy_par[i][enemy_coll_num].use)continue;
		enemy_.eep_.Set(enemy_.enemy_par[i][enemy_coll_num].emp.Position);
	}
	enemy_.SetUse(enemy_coll_num, false);

	player_.bar.SetBarr(player_.player_par.Position);
	//player_.ref.SetRef(player_.GetPlayerPos());
	player_.death = false;

	invincible = true;
	
}

void Stage::DeathUpdate_Enemy()
{
	if (enemy_coll_num >= 0) {
		//exp.SetExplosion(player_.GetPlayerPos().x, player_.GetPlayerPos().y);
		//player_.RedHP();
		dmg.SetTexNum(player_.GetHP());
		dmg.TakeDamage();
		d_inv = true;
		invincible = true;
	}
}

//----------Bulletの当たり判定処理_invincible-------------------------------

void Stage::InvincibleUpdate_EnemyBullet()
{
	//エネミーの弾がプレイヤーに衝突しているか
	if (bullet_coll_num >= 0) {
		enemy_.bln.SetFalse(bullet_coll_num);
		//exp.SetExplosion(enemy_.bln.GetPos(bul_coll_num).x, enemy_.bln.GetPos(bul_coll_num).y);
	}
}

void Stage::JustUpdate_EnemyBullet()
{
	if (bullet_coll_num >= 0) {
			enemy_.bln.SetFalse(bullet_coll_num);
			player_.bar.SetBarr(player_.player_par.Position);
		//	player_.ref.SetRef(player_.GetPlayerPos());
		invincible = true;
	}
}

void Stage::DeathUpdate_EnemyBullet()
{
	if (bullet_coll_num >= 0) {
		//exp.SetExplosion(player_.GetPlayerPos().x, player_.GetPlayerPos().y);
		//player_.RedHP();
		dmg.SetTexNum(player_.GetHP());
		dmg.TakeDamage();
		d_inv = true;
		invincible = true;
	}
}

void Stage::JustCounterUpdate()
{
	//ジャストガードのフレーム
	if (player_.just_counter >= 15) {

		player_.death = true;
		player_.just = false;
		player_.just_counter = 0;
	}
	else {
		player_.death = false;
		player_.just = true;
		player_.just_counter++;
	}
}

int Stage::DudgeCollisionEnemy()
{
	for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
		for (int j = 0; j < enemy_loop ; j++)
		{
			if (!enemy_.enemy_par[i][j].use)continue;
			float player_r = pow((player_.player_par.Size.y / 2 + player_.player_par.Size.x / 2) / 2, 2);

			float goal_r = pow((enemy_.enemy_par[i][j].emp.Size.x / 2 +
				enemy_.enemy_par[i][j].emp.Size.y / 2) / 2, 2);

			float dist = pow(((float)(player_.player_par.Position.x) -
				(float)(enemy_.enemy_par[i][j].emp.Position.x)), 2)
				+ pow(((float)(player_.player_par.Position.y) -
					(float)(enemy_.enemy_par[i][j].emp.Position.y)), 2);

			if (player_r + goal_r >= dist)
				return j;
		}
	}

	return -1;
}

int Stage::DudgeCollisionBullet()
{
	for (int i = 0; i < BULLETN_NUM_MAX; i++) {
		if (enemy_.bln.GetUse(i)) {
			float player_r = pow((player_.player_par.Size.y / 2 + player_.player_par.Size.x / 2) / 2, 2);
			float goal_r = pow(enemy_.bln.GetSize(i), 2);
			float dist = pow(((float)player_.player_par.Position.x - (float)enemy_.bln.GetPos(i).x), 2) 
				+ pow(((float)player_.player_par.Position.y - (float)enemy_.bln.GetPos(i).y), 2);
			if (player_r + goal_r >= dist) {
				return i;
			}
		}
	}
	return -1;
}

void Stage::EnemySetBullet()
{
	float rad = 0.0f;
	for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
		for (int j = 0; j < enemy_loop; j++) {
			if (enemy_.enemy_par[i][j].interval / hitStop ) {
				rad = atan2((float)player_.player_par.Position.y - (float)enemy_.enemy_par[i][j].emp.Position.y,
					(float)player_.player_par.Position.x - (float)enemy_.enemy_par[i][j].emp.Position.x);


				enemy_.bln.Set(enemy_.enemy_par[i][j].emp.Position,
					D3DXVECTOR2(cosf(rad) * BULLETN_SPEED, sinf(rad) * BULLETN_SPEED), 128.0f);

				enemy_.enemy_par[i][j].interval = false;

			}
		}
	}
}

void Stage::BossSetBullet()
{
}

void Stage::ShotBeam()
{
	if (!beam_fire)return;

	float rad = 0.0f;


	for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
		for (int j = 0; j < enemy_loop; j++) {
			if (enemy_.enemy_par[i][j].use) {
				rad = atan2(enemy_.enemy_par[i][j].emp.Position.y - player_.GetPlayerPos().y,
					enemy_.enemy_par[i][j].emp.Position.x - player_.GetPlayerPos().x);

				player_.beam.SetBeam(player_.GetPlayerPos(), rad * (180.0f / PI));
				beam_fire = false;
				break;
			}
		}
	}


}

//void Stage::ShotBeam_boss()
//{
//	if (!beam_fire || !boss.GetUse())return;
//	float rad = 0.0f;
//
//	rad = atan2(boss.GetPosition().y - player_.GetPlayerPos().y,
//		boss.GetPosition().x - player_.GetPlayerPos().x);
//
//	player_.beam.SetBeam(player_.GetPlayerPos(), rad * (180.0f / PI));
//	beam_fire = false;
//}

void Stage::EnemyCollBeam()
{
	int enemy_coll = -1;//どのエネミーにあたったのか
	int bull_coll = -1;//どの弾にあたったのか

	for (int i = 0; i < ENEMY_PATTERN_NUM; i++) {
		for (int j = 0; j < ENEMY_NUM_MAX; j++) {
			if (enemy_.enemy_par[i][j].use) {
				if (player_.beam.CollBeam(enemy_.GetEnemyPos(j), enemy_.GetEnemySize(j))) {
					enemy_coll = j;
					break;
				}
			}
		}
	}

	for (int i = 0; i < BULLETN_NUM_MAX; i++) {
		if (enemy_.bln.GetUse(i)) {
			if (player_.beam.CollBeam(enemy_.bln.GetPos(i), D3DXVECTOR2(enemy_.bln.GetSize(i), enemy_.bln.GetSize(i)))) {
				bull_coll = i;
				break;
			}
		}
	}

	if (enemy_coll < 0 && bull_coll < 0)return;


	if (enemy_coll >= 0) {


		enemy_.eep_.Set(enemy_.GetEnemyPos(enemy_coll));
		enemy_.SetUse(enemy_coll, false);
	}
	else {
		enemy_.bln.SetFalse(bull_coll);
		//enemy_.eep_.Set(enemy_.bln.GetPos(bull_coll));
		//exp.SetExplosion(enemy_.GetEnemyPos(bull_coll).x, enemy_.GetEnemyPos(bull_coll).y);
	}
}

//void Stage::BossCollBeam()
//{
//	//ボスにあたっているのかフラグ
//	bool boss_coll = player_.beam.CollBeam(boss.GetPosition(), boss.GetSize());
//
//	//どの弾にあたったのか
//	int bull_coll = -1;
//
//	for (int i = 0; i < BULLETN_NUM_MAX; i++) {
//		if (boss.bln.GetUse(i)) {
//			if (player_.beam.CollBeam(enemy_.bln.GetPos(i), MakeFloat2(enemy_.bln.GetSize(i), enemy_.bln.GetSize(i)))) {
//				bull_coll = i;
//				break;
//			}
//		}
//	}
//
//	if (!boss_coll && bull_coll < 0)return;
//
//
//	if (boss_coll) {
//		//ボスにダメージが入ったときのエフェクト
//		boss.RedHp();
//		exp.SetExplosion(boss.GetPosition().x, boss.GetPosition().y);
//	}
//	else {
//		exp.SetExplosion(boss.bln.GetPos(bull_coll).x, boss.bln.GetPos(bull_coll).y);
//		boss.bln.SetFalse(bull_coll);
//	}
//}

void Stage::InvincibleCount()
{
	if (invincible_count >= INVINCIBLE_TIME) {
		invincible_count = 0;
		invincible = false;
		jsg_flag = false;
		d_inv = false;
	}
	else if (invincible_count >= 60) {
		if (!d_inv && invincible_count == 60) {
			beam_fire = true;
		}
		invincible_count++;
	}
	else {
		invincible_count++;
	}
}

void Stage::PlayerInv()
{
	//無敵状態だったら、jsgのポジションを毎フレームplayerのposに更新する
	if (invincible) {
		if (player_.jsg.GetUse()) {
			player_.jsg.SetPos(player_.GetPlayerPos());
			player_.jsg.SetPosR(player_.GetPlayerPos());
			
		}
		else {
			if (jsg_flag == false) {
				player_.jsg.Set(player_.GetPlayerPos());
				jsg_flag = true;
			}
		}
		
	}
	else {
		player_.jsg.SetUse(false);
	}
}

void Stage::PlayerIsDead()
{
	if (player_.Dead()) {
		result = RESULT_LOSE;
		SceneTransition(SCENE_RESULT);
	}
}

