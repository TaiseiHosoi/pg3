#include "Enemy.h"
#include<iostream>


void Enemy::Initialize()
{
	isAlive = true;
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	if (isAlive == true) {
		printf("�����Ă�\n");
	}
	else if (isAlive == false) {
		printf("����ł�\n");
	}
	else
	{
		printf("��������������\n");
	}
}
