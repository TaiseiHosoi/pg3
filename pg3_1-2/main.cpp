#include <functional>
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


void ScanNum(int* num) {

	printf("’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");

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



int main() {

	srand(time(nullptr));

	int answerNum = 0;
	int playerNum = 0;
	int sec = 3;

	ScanNum(&playerNum);

	std::function<int()> NumLottery = [&answerNum]()
	{
		answerNum = rand() % 2 + 1;
		return answerNum;
	};

	std::function<void(std::function<void()>, int)> SetTimeOut = [=](std::function<void()> fx, int sec) {

		
		fx();

		printf("%d•b’â~\n", sec);
		Sleep(sec * 1000);
		
	};


	std::function<void(int,int)> CheckTheAnswer = [](int aNum,int  pNum) {

		if (aNum == 0 && pNum == 0 ||
			aNum == 1 && pNum == 1) {
			printf("³‰ğ!\n");
		}
		else {
			printf("•s³‰ğ\n");
		}
	};

	SetTimeOut(NumLottery, sec);
	CheckTheAnswer(answerNum,playerNum);

	return 0;
}