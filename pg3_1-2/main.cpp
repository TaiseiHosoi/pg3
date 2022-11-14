#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

typedef void (*PFunc)(int*);

enum OddEven
{
	Zero,
	Odd,
	Even,
};

void DispWaitTime(PFunc p,int sec, int *num) {

	p(num);
	
	printf("結果まで%d秒!\n", sec);
	Sleep(sec * 1000);

}

void CheckTheAnswer(int* num) {

	int result = rand() % 2 + 1;

	if (result == 0 && *num == 0 ||
		result == 1 && *num == 1) {
		printf("正解!\n");
	}
	else {
		printf("不正解\n");
	}
}

void ScanNum(int* num) {

	printf("値を入力してください。\n");

	scanf_s("%d", num);

	if (*num % 2 == 0) {
		*num = Even;
	}
	else if (*num % 2 == 1) {
		*num = Odd;
	}
	else {
		printf("error\n");
	}
}


void HalfABlock() {

	PFunc p;

	int playerNum = 0;
	int sec = 3;

	p = ScanNum;

	DispWaitTime(p,sec,&playerNum);
	
	CheckTheAnswer(&playerNum);
	
}

int main() {

	srand(time(nullptr));

		
	HalfABlock();


	return 0;
}