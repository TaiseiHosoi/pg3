#include "Rectangle.h"
#include<iostream>

void Rectangle::Draw()
{
	printf("四角ができた!\n");
}

void Rectangle::Size()
{
	float height = 2;
	float width = 2;
	printf("%f\n", height * width);
}
