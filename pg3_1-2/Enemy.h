#pragma once
class Enemy
{
public:
	void Initialize();
	void Update();
	void Draw();

public:
	void Move1();
	void Move2();
	void Move3();

private:
	static void (Enemy::*moveFuncTable[])();

	int movePhase;
	
public:

	static bool isAlive;
};

