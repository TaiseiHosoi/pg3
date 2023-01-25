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
		printf("生きてる\n");
	}
	else if (isAlive == false) {
		printf("死んでる\n");
	}
	else
	{
		printf("何かがおかしい\n");
	}
}

void Enemy::Move1()
{
	printf("接近\n");
	movePhase = 1;

}

void Enemy::Move2()
{
	printf("射撃\n");
	movePhase = 2;
}

void Enemy::Move3()
{
	printf("離脱\n");
	movePhase = 0;
}


