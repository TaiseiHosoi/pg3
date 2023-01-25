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
