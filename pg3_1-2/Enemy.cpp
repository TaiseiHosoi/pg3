#include "Enemy.h"
#include<iostream>

void(Enemy::* Enemy::moveFuncTable[])() = {
	&Enemy::Move1,
	&Enemy::Move2,
	&Enemy::Move3
};

enum Class {
	approach,
	shoot,
	secession
};

void Enemy::Initialize()
{
	isAlive = true;
	movePhase = 0;
}

void Enemy::Update()
{
	(this->*moveFuncTable[movePhase])();
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

void Enemy::Move1()
{
	printf("�ڋ�\n");
	movePhase = 1;

}

void Enemy::Move2()
{
	printf("�ˌ�\n");
	movePhase = 2;
}

void Enemy::Move3()
{
	printf("���E\n");
	movePhase = 0;
}


