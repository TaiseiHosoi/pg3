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


	int playerNum = 0;
	int sec = 3;

	std::function<void(PFunc, int, int)> SetTimeOut = [](PFunc p, int sec, int num) {

		p(&num);

		printf("%d•b’â~\n", sec);
		Sleep(sec * 1000);
	};

	SetTimeOut(ScanNum, sec, playerNum);

	std::function<void(int)> CheckTheAnswer = [](int num) {
		int result = rand() % 2 + 1;

		if (result == 0 && num == 0 ||
			result == 1 && num == 1) {
			printf("³‰ğ!\n");
		}
		else {
			printf("•s³‰ğ\n");
		}
	};

	CheckTheAnswer(playerNum);

	return 0;
}