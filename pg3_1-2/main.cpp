#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

typedef void (*PFunc)(int*);

void CheckTheAnswer(int* num) {
	int result;
	result = rand() + 1;

	printf(" �o�ځF%d\n", result);

	if (result % 2 == 0 && *num % 2 == 0 ||
		result % 2 == 1 && *num % 2 == 1) {
		printf("����\n");
	}
	else {
		printf("�s����\n");
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

void ScanNum(int* num) {

	printf("�l����͂��Ă�������\n");

	scanf_s("%d", num);
	if (*num % 2 == 0) {
		printf("���������͂���܂���\n");
		*num = 2;
	}
	else if (*num % 2 == 1) {
		printf("������͂���܂���\n");
		*num = 1;
	}
	else {
		printf("error\n");
	}
}

int main() {

	srand(time(nullptr));

	int standby = 1000;	//�ҋ@����
	HalfABlock(standby);

	return 0;
}