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
		printf("生きてる\n");
	}
	else if (isDead == false) {
		printf("死んでる\n");
	}
	else
	{
		printf("何かがおかしい\n");
	}
}
