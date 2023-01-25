#pragma once
#include "IShape.h"
class Circle :public IShape
{
public:
	void Draw()override;
	void Size()override;
	
};
