#pragma once
#include "main.h"
#include "renderer.h"
class ItemPrm :public ParameterFrame{};

class Item 
{
public:
	virtual void Initialize()=0;
	virtual void Terminate()=0;
	virtual void Update()=0;
	virtual void Draw()=0;

	virtual void SetItem(D3DXVECTOR2 pos, D3DXVECTOR2 size)=0;
	virtual bool Collition(D3DXVECTOR2 pos, D3DXVECTOR2 size)=0;
};

