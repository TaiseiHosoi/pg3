#include "Enemy.h"
#include<iostream>


void Enemy::Initialize()
{
	isDead = true;
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	if (isDead == true) {
		printf("�����Ă�\n");
	}
	else if (isDead == false) {
		printf("����ł�\n");
	}
	else
	{
		printf("��������������\n");
	}
}
