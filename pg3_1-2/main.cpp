#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

typedef void (*PFunc)(int*);

void CheckTheAnswer(int* num) {
	int result;
	result = rand() % 2 + 1;

	printf("出目：%d\n", result);

	if (result % 2 == 0 && *num % 2 == 0 ||
		result % 2 == 1 && *num % 2 == 1) {
		printf("正解!\n");
	}
	else {
		printf("不正解\n");
	}
}



enum OddEven
{
	Zero,
	Odd,
	Even,
};

void ScanNum(int* num) {

	printf("値を入力してください\n");

	scanf_s("%d", num);

	if (*num % 2 == 0) {
		printf("偶数が入力されました\n");
		*num = Even;
	}
	else if (*num % 2 == 1) {
		printf("奇数が入力されました\n");
		*num = Odd;
	}
	else {
		printf("error\n");
	}
}

void HalfABlock(int second) {

	PFunc p;

	int playerNum;
	p = ScanNum;
	p(&playerNum);

	Sleep(second);

	p = CheckTheAnswer;
	p(&playerNum);
}

int main() {

	srand(time(nullptr));

	int standby = 1000;	//待機時間
	HalfABlock(standby);

	return 0;
}