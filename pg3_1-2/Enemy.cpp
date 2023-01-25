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
		printf("¶‚«‚Ä‚é\n");
	}
	else if (isDead == false) {
		printf("€‚ñ‚Å‚é\n");
	}
	else
	{
		printf("‰½‚©‚ª‚¨‚©‚µ‚¢\n");
	}
}
