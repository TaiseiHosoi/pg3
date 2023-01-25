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
		printf("¶‚«‚Ä‚é\n");
	}
	else if (isAlive == false) {
		printf("€‚ñ‚Å‚é\n");
	}
	else
	{
		printf("‰½‚©‚ª‚¨‚©‚µ‚¢\n");
	}
}

void Enemy::Move1()
{
	printf("Ú‹ß\n");
	movePhase = 1;

}

void Enemy::Move2()
{
	printf("ËŒ‚\n");
	movePhase = 2;
}

void Enemy::Move3()
{
	printf("—£’E\n");
	movePhase = 0;
}


