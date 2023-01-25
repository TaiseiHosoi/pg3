#pragma once
#include "IShape.h"
class Rectangle :public IShape
{
public:
	void Draw()override;
	void Size()override;

};

