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
