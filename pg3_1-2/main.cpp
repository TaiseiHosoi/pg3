
#include <iostream>
//#include"windows.h"

#include"Circle.h"
#include"Rectangle.h"
#include"IShape.h"



int main()
{
    Circle *circle_ = new Circle;
    Rectangle *rectangle_ = new Rectangle;

    circle_->Size();
    rectangle_->Size();

    circle_->Draw();
    rectangle_->Draw();



    system("pause");
    return 0;
}